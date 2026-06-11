#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
#define pb(n,m) n.push_back(m)
#define fix(n) cout<<fixed<<setprecision(n);
using namespace std;
//using bint=boost::multiprecision::cpp_int;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;

int main(){
  int n,ans=0; string s;
  cin>>n>>s;
  vvi v(10);
  rep(i,0,n){
    int w=s[i]-48;
    pb(v[w],i);
  }
  
  rep(i,0,1000){
    int a=i/100,b=i%100/10,c=i%10;
    int x,y,z;
    if(v[a].size()==0) continue;
    x=v[a][0];
    
    y=lower_bound(all(v[b]),x+1)-v[b].begin();
    if(y==v[b].size()) continue;
    
    z=lower_bound(all(v[c]),v[b][y]+1)-v[c].begin();
    if(z==v[c].size()) continue;
    ans++;
  }
  co(ans); 
  
  return 0;
}