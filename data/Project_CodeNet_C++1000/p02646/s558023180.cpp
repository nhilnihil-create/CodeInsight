#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//print(fixed << setprecision(10));
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define repk(i,n,k) for(ll i = k; i < (n); i++)
#define all(n) n.begin(), n.end()
#define print(n) cout << n << endl
double PI = acos(-1.0);
int INF = 1e9;
ll LINF = 1e18;
ll MOD = 1e9+7;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll a,b,v,w,t;
    cin >> a >> v >> b >> w >> t;
    if(abs(a-b) <= (v-w)*t) print("YES");
    else print("NO");
    return 0;
}