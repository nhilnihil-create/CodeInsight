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
    
    ll n,a,cnt=1;
    cin >> n;
    vector<ll> table(1e6+1,0);
    rep(i,n){
        cin >> a;
        for(ll j=2; j*j<=a; j++){
            if(a%j==0){
                while(a%j==0) a/=j;
                table[j]++;
                cnt=max(cnt,table[j]);
            }
        }
        if(a!=1){
            table[a]++;
            cnt = max(cnt,table[a]);
        }
    }
    if(cnt==1) print("pairwise coprime");
    else if(cnt!=n) print("setwise coprime");
    else print("not coprime");
    return 0;
}