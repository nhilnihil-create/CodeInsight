#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    ll A,B;
    cin >> A >> B;
    ll C = min(A,B);
    ll g = 1;
    for(int i = C; i > 0; --i){
        if(A%i == 0 && B%i == 0){
            g = i;
            break;
        }
    }
    ll x = A / g;
    ll y = B / g;
    ll ans = x * y * g;
    cout << ans << endl;
}