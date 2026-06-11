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
int n,k;
cin>>n>>k;
int R,S,P;
cin>>R>>S>>P;
map<char,int>price;
price['r']=R;
price['s']=S;
price['p']=P;
string st;
map<char,char>tt;
tt['s']='r';
tt['p']='s';
tt['r']='p';
cin>>st;
string r={};
for(int i=0;i<st.length();i++)
{
  if(st[i]=='r')
    r+='p';
  else if(st[i]=='p')
    r+='s';
  else
  {
    r+='r';
  }
}
int nn=r.length();
 for(int i=k;i<nn;i++)
 {
    if(r[i-k]==r[i])
    {
     
      if(i+k<nn)
     { 
      if(r[i]==r[i+k])
       r[i]=st[i];
      else
       r[i]='r'+'s'+'p'-r[i-k]-r[i+k];
     }
     else
     {
       r[i]=st[i];
     }
    }
 }
 int ans=0;
 for(int i=0;i<nn;i++)
 {
  if(r[i]==tt[st[i]])
  ans+=price[r[i]];
 }
//cout<<r<<endl;
cout<<ans<<endl;
}