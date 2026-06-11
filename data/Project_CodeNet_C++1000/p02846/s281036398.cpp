#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int t1,t2;
  cin>>t1>>t2;
  PII a,b;
  
  cin>>a.F>>a.S>>b.F>>b.S;
  
  
  a.F*=t1;
  a.S*=t2;
  b.F*=t1;
  b.S*=t2;
  int f=a.F-b.F,s=a.S-b.S;
  if(f>0){
    f*=-1;
    s*=-1;
  }
  if((f+s)==0){cout<<"infinity"<<endl;return 0;}
  else if((f+s)<0){cout<<0<<endl;return 0;}
  else{
    int x=-f/(f+s),y=f%(f+s);
    if(y!=0) cout<<x*2+1<<endl;
    else cout<<x*2<<endl;
  }
       
  
    
    
    


  return 0;
}
