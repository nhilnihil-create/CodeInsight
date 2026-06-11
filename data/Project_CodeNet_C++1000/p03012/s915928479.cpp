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
  int n,c=0,d=0,ans=1000000;
  cin>>n;
  vector<int> a(n);
  rep(i,0,n){
    cin>>a[i];
    c+=a[i];
  }
  rep(i,0,n-1){
    d+=a[i];
    c-=a[i];
    ans=min(ans,abs(c-d));
  }
  co(ans);
  
  return 0;
}