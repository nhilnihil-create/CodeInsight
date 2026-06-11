#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <limits>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

int main(){
    ll n;
    cin >> n;
    ll a[n+1];
    ll a_max = -1;
    rep1(i,n){
        cin >> a[i];
        a_max = max(a[i], a_max);
    }
    ll tmp = 1;
    ll mod = 1e9 + 7;
    ll count = 0;
    rep0(i, 60){
        ll count1 = 0;
        rep1(j, n){
            if((a[j] >> i) & 1) count1++;
        }
        ll tmp_expo =  tmp % mod;
        ll tmp_count1 = (count1*(n-count1)) % mod;
        count += (tmp_expo*tmp_count1) % mod;
        tmp *= 2;
    }
    count %= mod;
    cout << count <<endl;
    return 0;
}