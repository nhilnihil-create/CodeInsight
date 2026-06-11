#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I wanna be the wind
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
    ll n;
    cin>>n;
    ll vet[n+2];
    rep(i,0,n){
        cin>>vet[i];
    }
    ll ans=0;
    rep(i,0,n){
        rep(j,i+1,n){
            rep(k,j+1,n){
                vector<ll> nums(3);
                nums[0]=vet[i];
                nums[1]=vet[j];
                nums[2]=vet[k];
                sort(all(nums));
                if(vet[i]!=vet[j] && vet[j]!=vet[k] && vet[i]!=vet[k] && nums[0]+nums[1]>nums[2]){
                    // cout<<vet[i]<<" "<<vet[j]<<" "<<vet[k]<<endl;
                    ans++;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;  
}   