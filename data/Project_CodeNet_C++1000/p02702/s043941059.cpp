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
  string s;
  cin>>s;
  int moding[s.size()+1 ];
  moding[0]=0;
  map<int,int> mp;
  mp[moding[0]]++;
  reverse(s.begin(),s.end() );
  int num=1;
  repi(i,1,s.size()+1 ){
    if(i!=1){
      num*=10;
      num%=2019;
    }
    moding[i]=moding[i-1]+(s[i-1]-'0')*num;
    moding[i]%=2019;
    // cout<<moding[i]<<endl;
    mp[moding[i]]++;
  }
  
  int ans=0;
  for(auto itr=mp.begin();itr!=mp.end();itr++){
    ans+=(itr->S*(itr->S-1))/2;
  }
  cout<<ans<<endl;
  return 0;
}
