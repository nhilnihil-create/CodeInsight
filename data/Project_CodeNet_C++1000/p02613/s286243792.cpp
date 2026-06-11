#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vpi vector<pii>
#define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf INT_MAX
#define minf INT_MIN
#define dd double
#define fori(x,n) for(ll i=x;i<n;i++)
#define modd 998244353
#define umap unordered_map<ll,ll>
#define mmap map<ll,ll>
#define mm 100000000


int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    
    ll t;
    t=1;
    // cin>>t;
    while(t--){
      ll n;
      cin>>n;
      ll a=0,b=0,c=0,d=0;

      while(n--){
        string s;
        cin>>s;
        if(s=="AC")a++;
        else if(s=="WA")b++;
        else if(s=="TLE")c++;
        else d++;
      }

      cout<<"AC"<<" x "<<a<<"\n";
      cout<<"WA"<<" x "<<b<<"\n";
      cout<<"TLE"<<" x "<<c<<"\n";
      cout<<"RE"<<" x "<<d<<"\n";








      

       




     

    






      
  
    }





return 0;
}     

