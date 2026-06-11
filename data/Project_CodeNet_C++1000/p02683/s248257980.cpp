#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define initdp(a, b)  for (int i = 0; i <= a; i++)   for (int j = 0; j <= b; j++) dp[i][j] = -1;
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 1000005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<int,int>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
using namespace std;

int fun(int n, int k) {
  return (((ll)n>>(ll)k)&1);
}


void solve(){
    

  ll n,m,x;
  cin>>n>>m>>x;


  vecl c(n);

  vector<vecl> a(n,vecl(m));


  rep(i,n){
      cin>>c[i];
      rep(j,m)cin>>a[i][j];
  }



  ll ans=INF;

  rep(bit,1<<n){
      vecl ok(m,0);
      ll cost=0;

      
      rep(i,n){
        if(fun(bit,i)){
            cost+=c[i];
            rep(j,m)ok[j]+=a[i][j];
        }
      }


      bool check=true;


      rep(i,m){
          if(ok[i]<x)check=false;
      }


      if(check)
        ans=min(ans,cost);
  }


  if(ans>=INF)
    cout<<-1<<endl;
  else cout<<ans<<endl;


 
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}