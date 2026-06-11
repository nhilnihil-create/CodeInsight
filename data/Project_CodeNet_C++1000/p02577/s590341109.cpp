#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define ld long double
#define pb push_back 
#define ff first 
#define ss second
#define all(c) c.begin(), c.end()
#define sz(z) (int)z.size()
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rev(i,a,b) for(int i=a; i>=b; i--)
//Debugging tools 
#define debug(v) cout<<#v<<endl;for(ll i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define debugn(v,n) cout<<#v<<endl;for(ll i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
#define deb(sum) cout<<#sum<<" = "<<sum<<endl;
//Predefined values
#define INF (ll)1e18
#define endl "\n"
#define pi 3.142857142857143
const ll MOD = 1e9 + 7;


int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
    int t=1;    
    //cin>>t;
    while(t--){
        string n;
        cin>>n;
        ll sm = 0;
        rep(i,0,sz(n)){
            sm += n[i] - '0';
        }
        if(sm%9==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        
    }
  return 0;
 }















