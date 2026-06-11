#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double
#define mod 1000000007
const ll N=1e6+10;
ll m[N+1];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    REP(i,n){
        ll t;
        cin>>t;
        arr[i]=t;
        m[t]++;
    }
    ll ans=0;
    REP(j,n){
        ll elem=arr[j];
        m[elem]=m[elem]-1;
        vector<ll> fact;
        for(ll i=1;i<=sqrt(elem);i++){
            if(elem%i==0){
                if(elem/i==i){
                    fact.pb(i);
                }
                else{
                    fact.pb(elem/i);
                    fact.pb(i);
                }
            }
        }
        ll flag=1;
        for(auto & x:fact){
            if(m[x]){
                flag=0;
                break;
            }
        }
        if(flag){
            ans++;
        }
        m[elem]++;
    }
    cout<<ans<<endl;

}
