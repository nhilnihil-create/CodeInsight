#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 100009 /// Still trying to be normal
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e17 + 9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(n&1){
        rep(i,1,m+1){
            cout<<i<<" "<<n-i<<'\n';
        }
    }
    else{
        ll fim=n;
        rep(i,1,m+1){
            ll clock = fim-i;
            ll antic = n-fim+i;
            // cout<<clock<<" "<<antic<<endl;
            if(clock>antic){
                cout<<i<<" "<<fim<<'\n',fim--;
                // fim--;
            }
            else{
                cout<<i<<" "<<fim-1<<'\n',fim--;
            }
        }
    }
    return 0;   
}