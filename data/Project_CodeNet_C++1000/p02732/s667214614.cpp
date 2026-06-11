#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vlli vector<ll>
#define vi vector<int>
#define vs vector<string>
#define vplli vector< pair< ll,ll> >
#define plli pair< ll,ll >
#define vps vector< pair< string, string> >
#define vpi vector< pair< int, int> >
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn(i,n) for(ll i=0;i<n;i++)
#define print(arr,a,n) for(ll i=(a);i<(n);i++)cout<<(arr)[i]<<" ";

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    ll n;
    cin>>n;
    ll a[n], z=0;
    map<ll,ll> m;
    forn(i,n){
        cin>>a[i];
        m[a[i]]++;
    }
    map<ll,ll>::iterator it;
    vlli ans(n, 0);
    
    for(it = m.begin(); it != m.end(); it++){
        z += (it->S * (it->S - 1))/2;
    }
    
    forn(i,n){
        ll x=m[a[i]];
        ans[i] = z - (x*(x-1))/2 + ((x-1)*(x-2))/2;
    }
    
    print(ans,0,ans.size());
    cout<<endl;

}