#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  bool flag=true;
  string s;cin>>s;
  bool tag=true;
  for (int i = b; i < d; i++)
  {
    if(s[i-1]=='.'&&s[i]=='.'){
      if(s[i-2]=='.'){
        tag=false;
      }
    }
    if(s[i]=='#'&&s[i-1]=='#'){
      flag=false;
    }
  }
  if(tag)s[d-1]='#';
  for (int i = a; i < c; i++)
  {
    if(s[i]=='#'&&s[i-1]=='#'){
      flag=false;
    }
  }
  	if(flag){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  return 0;
}
