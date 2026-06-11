#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define N 100005
#define ll long long
#define ull unsigned long long
#define loop1(i, j, k, step) for (int i=j; i<k; i+=step)
#define loop(i, j, k) for (int i=j; i<k; i++) 
#define rloop1(i, j, k, step) for (int i=j; i>=k; i-=step)
#define rloop(i, j, k) for(int i=j; i>=k; i--)
#define rep(i, k) for(int i = (0); i < (k); i++ )
#define rrep(i, k) for(int i = k-1; i >= 0; i-- )

#define forall(it, l) for(auto it=l.begin(); it != l.end(); it++)
#define mp make_pair
#define pb push_back
#define pop pop_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define endl "\n"
#define Max (int)INT_MAX
#define Min (int)INT_MIN
#define MEM(a, b) memset(a, (b), sizeof(a))
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL)
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;


void solve()
{
  int n,k,l;
  cin>>n;
  vi a;
  rep(i,n){
    cin>>k;
    a.pb(k);
  }
  l = a[0];
  ll z =0;
  loop(i,1,n){
    if(a[i]<l){
      z += abs(l-a[i]);
    }
    else
      l = a[i];
  }
  cout<<z<<endl;
}
int  main() 
{
  auto start=clock();
  fast_io;
    int t=1;
    //cin>>t;
    while(t--){
      solve();
    }
    auto stop =clock();
    cerr<<"time taken:"<<double(stop-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
  return 0; 
}
