#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define Rep(i,n) for(ll i=0;i<n;i++) 
#define rRep(i,n) for(ll i=n;i>=0;i--)
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=b;i>=a;i--)
#define itr(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) 
#define vi vector<int>  
#define vl vector<ll> 
#define vul vector<ull>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define Si set<int> 
#define Mi multiset<int> 
#define Sl set<ll> 
#define Ml multiset<ll>
#define mapi map<int,int>
#define mapl map<ll,ll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second  
#define INF (ll)1e9;
#define mod (ll)(1e9+7);
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define T ll test;cin >> test;while(test--)

int main(){
    fast;      
    ll n;cin>>n;
    vector<pair<ll,ll>> vv(n);
    ll x,y;
    Rep(i,n){
        cin>>x>>y;
        vv[i]=mp(x,y);
    }
    ll d=0;
    for(int i=0;i<=n-3;i++){
        if(vv[i].ff==vv[i].ss&&vv[i+1].ff==vv[i+1].ss&&vv[i+2].ff==vv[i+2].ss){
            cout<<"Yes"<<endl;
            d=1;
            break;
        }
    }
    if(!d){
        cout<<"No"<<endl;
    }
return 0;
}
