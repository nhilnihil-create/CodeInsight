#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;

int main()
{
  fastio; 
  cout<<fixed<<setprecision(7);
  int n;
  cin>>n;
  vector<double> a(n);
  range(i,0,n)cin>>a[i];
  sort(all(a));
  double ans=0;
  ans=(a[0]+a[1])/2;
  for(int i=2;i<n;i++)
  {
    ans=(ans+a[i])/2;
  }
  cout<<ans;

}
