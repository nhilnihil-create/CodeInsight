#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a,b;
    a=divisor(n);
    b=divisor(n-1);
    ll ans = 0;
    for (ll c : a){
        ll x = n;
        if(c==1) {continue;}
        else{
            while(x%c==0){
                x = x/c;
            }
            if(x%c==1){
                ans++;
            }
        }
    }
    ans+=(b.size()-1);
    cout << ans <<endl;
}