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
//#define endl '\n'
#define dbv(v) cout<<endl;cout<<#v<<"-->> ";for(auto it:v){cout<<it<<" ";}cout<<endl;
#define dbm(m)cout<<endl;cout<<#m<<"-->> ";for(auto it:m){cout<<it.fi<<" "<<it.se.fi<<" "<<it.se.se<<endl;}
#define dbs(s)cout<<endl;cout<<#s<<"-->> ";for(auto it:s){cout<<it<<" ";}cout<<endl;
#define mod 1000000007
#define db1(x) cout<<#x<<"="<<x<<endl;
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl;
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl;
#define mx 1e18
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define double long double
#define re(s) reverse(s.begin(),s.end())
#define io std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
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
cin>>n;
string s;
cin>>s;
vector<int>prer(n,0),preb(n,0),preg(n,0);
for(int i=n-1;i>=0;i--)
{
  if(i==n-1)
  {
    if(s[i]=='R')prer[i]=1;
    else if(s[i]=='G')preg[i]=1;
    else preb[i]=1;continue;
  }
  if(s[i]=='R')
  {
    prer[i]=prer[i+1]+1;
  }
  else
  {
    prer[i]=prer[i+1];
  }
  if(s[i]=='G')
  {
    preg[i]=preg[i+1]+1;
  }
  else
  {
    preg[i]=preg[i+1];
  }
  if(s[i]=='B')
  {
    preb[i]=preb[i+1]+1;
  }
  else preb[i]=preb[i+1];
}
//dbv(prer)
int ans=0;
for(int i=0;i<n-2;i++)
{
  for(int j=i+1;j<n-1;j++)
  {
     if(s[i]!=s[j])
     {
      
        char c='R'+'G'+'B'-s[i]-s[j];
        if(c=='R'){ans+=prer[j+1];if(2*j-i>=n)continue;if(s[2*j-i]=='R')ans--;}
        else if(c=='G'){ans+=preg[j+1];if(2*j-i>=n)continue;if(s[2*j-i]=='G')ans--;}
        else {ans+=preb[j+1];if(2*j-i>=n)continue;if(s[2*j-i]=='B')ans--;}
     }
  }
}
cout<<ans<<endl;
}