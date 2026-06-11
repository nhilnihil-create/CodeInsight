#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define fi first
#define se second
#define pb push_back
#define soo(v) sort(v.rbegin(),v.rend())
#define so(v) sort(v.begin(),v.end())
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define endl '\n'
#define dbv(v) cout<<endl;cout<<#v<<"-->> ";for(auto it:v){cout<<it<<" ";}cout<<endl;
#define dbm(m)cout<<endl;cout<<#m<<"-->> ";for(auto it:m){cout<<it.fi<<" "<<it.se<<endl;}
#define dbs(s)cout<<endl;cout<<#s<<"-->> ";for(auto it:s){cout<<it<<" ";}cout<<endl;
#define mod 2019
#define db1(x) cout<<#x<<"="<<x<<endl;
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl;
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl;
#define mx 1e18
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define double long double
#define re(s) reverse(s.begin(),s.end())
#define io std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pp 1000000000000000000
int powe(int x,int n)
{
  if(n==0)return 1;
  if(n%2==0)
    return powe((x%mod*x%mod)%mod,n/2)%mod;
  return (x%mod*powe((x%mod*x%mod)%mod,(n-1)/2))%mod;
}
int gcd(int A,int B)
{
  if(B==0)return A;
  return gcd(B,A%B);
}
int32_t main()
{
  io
int n;
cin>>n;map<int,int>m;int nn=n;
for(int i=2;i<=sqrt(n);i++)
{
 while(n%i==0)
 {
  n/=i;
  m[i]++;
 }
}
if(n>2)
{
  m[n]++;
}
//dbm(m);
vector<int>vv;
for(auto it:m)
{
  for(int j=1;j<=it.second;j++)
  {
    vv.pb(pow(it.first,j));
  }
}int ans=0;

  for(int i=0;i<vv.size();i++)
  {
    if(nn%vv[i]==0)
    {
      ans++;
      nn/=vv[i];
      
    }
  }
//dbv(vv)
cout<<ans<<endl;
}