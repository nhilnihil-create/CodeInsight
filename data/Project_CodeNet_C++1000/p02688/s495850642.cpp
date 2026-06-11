#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long
#define llv vector<long long>
#define assign_max(into, compared) (into = max((into), (compared)))
#define assign_min(into, compared) (into = min((into), (compared)))
#define rep(i,n) for(long long i = 0;i < n;i++)

using namespace std;

int main(void){
    ll n,k;
    cin >> n >> k;
    llv v (n,0);
    rep(i,k){
        ll d;
        cin >> d;
        rep(j,d){
            ll a;
            cin >> a;
            v[a-1] = 1;
        }
    }
    ll cnt = 0;
    rep(i,n) if (v[i] == 0) cnt++;
    cout << cnt;
    return 0;
}