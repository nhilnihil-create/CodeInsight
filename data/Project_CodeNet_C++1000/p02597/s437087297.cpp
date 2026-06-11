#include <bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for (ll i=a;i<n;i++)
#define loopm(i,a,n) for (ll i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define tr(container,it)\
for(auto it=container.begin();it!=container.end();it++)
#define SZ(x) ((int)(x).size())
#define WGraph(n) vector < vector < pair < ll , ll > > >(n)
typedef vector<long long> VI;
typedef long long ll;
typedef vector < vector < ll > > VII;
typedef pair<ll,ll> PII;
typedef double db;
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    string s="";
    cin>>s;
    vector<ll> posi;
    loopm(i,0,n)
    if(s[i]=='R')
      posi.pb(i);
    ll ans=0;
    ll j=0;
    loop(i,0,n){
      if(s[i]=='W'){
        if(j>=0&&j<posi.size()){
           if(posi[j]>i){
            ans++;
            swap(s[i],s[posi[j]]);
            j++;
           }
        }
      }
    }
    cout<<ans<<"\n";
}
