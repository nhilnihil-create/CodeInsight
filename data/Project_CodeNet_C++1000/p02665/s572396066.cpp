#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define ll              long long
#define dd              double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<long long>
#define vdd             vector<double>
#define vpii            vector<pair<int,int>>
#define vpll            vector<pair<long long,long long>>
#define vvi             vector<vector<int>>
#define vvll            vector<vector<long long>>
#define mii             map<int,int>
#define mll             map<long long,long long>
#define umii            unordered_map<int,int>
#define umll            unordered_map<long long,long long>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define rep(i,n)        for(int i=0;i<n;i++)
#define rep2(i,a,b)     for(int i=a;i<b;i++)
#define rev(i,n)        for(int i=n;i>=0;i--)
#define rev2(i,a,b)     for(int i=a;i>=b;i--)
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             9e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define wh(x)           int x; cin>>x; while(x--)
#define fio             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl            '\n'
#define all(x)          x.begin(),x.end()
#define d0(x)           cout <<x<<" "
#define d1(x)           cout <<x<<endl
#define d2(x,y)         cout <<x<<" "<<y<<endl
#define d3(x,y,z)       cout <<x<<" "<<y<<" "<<z<<endl
#define d4(x,y,z,w)     cout <<x<<" "<<y<<" "<<z<<" "<<w<<endl
#define read2(x,y)      cin>>x>>y
#define read3(x,y,z)    cin>>x>>y>>z
#define read4(x,y,z,w)  cin>>x>>y>>z>>w
#define read5(x,y,z,w,a)cin>>x>>y>>z>>w>>a
#define sz(a)           (int)a.size()
#define deb(x)          cout <<#x << " is "<<x<<endl;
const ll mod=1e9+7;
const double PI = 3.14159265359;
const ll MOD=998244353;
void i_o()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}

ll help(vll& A){
  ll n=A.size()-1;
 // ll tot=0;
  if(n==0){
    if(A[0]==1){
      return 1;
    }
    return -1;
  }
  if(A[0]!=0) return -1;
  //d1("OK");
  ll x=1,i=0,tot=0,ma=LLONG_MAX/2;
  vll upmax(n+1,1);
  for(i=1;i<=n;i++){
    ll iss=2*x;
    if(iss>ma) iss=ma;
    upmax[i]=iss;
    //tot+=iss;
    if(A[i]>iss){
   //   d1("here");
      return -1;
    }
    x=iss-A[i];
   // deb(x);
  }
  //if(2*x<A[n]) return -1;
  ll prev=A[n];
  tot=A[n];
 // d1("sure");
  for(int i=n-1;i>=0;i--){
    ll x_mi=ceil((dd)(prev+2*A[i])/2.0);
    ll x_ma=min(upmax[i],prev+A[i]);
    if(x_mi>x_ma) return -1;
    tot+=x_ma;
    prev=x_ma;
  }
  return tot;
}
int main(){
  fio
  i_o();
  int n;
  cin>>n;
  vll A(n+1);
  rep(i,n+1) cin>>A[i];
  d1(help(A));
  return 0;
}
