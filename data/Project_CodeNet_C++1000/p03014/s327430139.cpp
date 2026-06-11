#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
#define pb(n,m) n.push_back(m)
#define pi(n,m) n.insert(n.begin(),m);
#define ee(n) n.erase(n.end()-1)
#define eb(n) n.erase(n.begin())
#define check(n) reverse(all(n));rep(z,0,n.size())cout<<n[z];co("");reverse(all(n));
using namespace std;
//using bint=boost::multiprecision::cpp_int;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  int n,m,c=0,ans=0;
  bool f=true;
  cin>>n>>m;
  vector<string> s(n);
  rep(i,0,n) cin>>s[i];
  int x[n][m],y[n][m];
  rep(i,0,n){
    rep(j,0,m){
      x[i][j]=0;
      y[i][j]=0;
    }
  }
  
  rep(i,0,n){
    rep(j,0,m){
      if(s[i][j]=='#'){
        c=0;
        continue;
      }
      c++;
      x[i][j]=c;
    }
    c=0;
  }
  rep(i,0,m){
    rep(j,0,n){
      if(s[j][i]=='#'){
        c=0;
        continue;
      }
      c++;
      y[j][i]=c;
    }
    c=0;
  }
  int a=0;
  rep(i,0,n){
    rep(j,0,m){
      if(a==0) a=x[i][m-j-1];
      else if(x[i][m-j-1]!=0) x[i][m-j-1]=a;
      else a=0;
    }
    a=0;
  }
  a=0;
  rep(i,0,m){
    rep(j,0,n){
      if(a==0) a=y[n-j-1][i];
      else if(y[n-j-1][i]!=0) y[n-j-1][i]=a;
      else a=0;
    }
    a=0;
  }
  rep(i,0,n) rep(j,0,m) x[i][j]+=y[i][j];

  rep(i,0,n) rep(j,0,m) ans=max(ans,x[i][j]);
  co(ans-1);
  
  return 0;
}