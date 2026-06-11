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
  int n;
  cin>>n;
  int a=n%100;
  a+=4; a/=5;
  if(n/100>=a) co(1);
  else co(0);
  
  
  return 0;
}