#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    ll N;
    ll ans = 0;
    cin >> N;
    if(N%2 == 1||N==0) cout << 0 << endl;
    else{
        N /= 2;
        ll i = 1;
        while(pow(5,i) <=  N){
            ll x = pow(5,i);
            ans += N / x;
            i++;
        }
        cout << ans << endl;
    }
}