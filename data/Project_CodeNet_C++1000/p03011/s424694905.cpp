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
  int a[3];
  rep(i,0,3) cin>>a[i];
  sort(a,a+3);
  co(a[0]+a[1]);
  
  return 0;
}