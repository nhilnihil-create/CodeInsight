#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define EPS (1e-9)
#define INF (1e17)
#define PI (acos(-1))
//const double PI = acos(-1);
//const double EPS = 1e-15;
//long long INF=(long long)1E17;
#define i_7 (long long)(1e9+7)
//#define i_7 998'244'353
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
long long po(long a, long b){
    if(b==0){
        return 1;
    }
    
    long long z = po(a,b/2);
    z = mod(z*z);
    if(b%2!=0){
        z = mod(a*z);
    }
    return z;
}
 
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=std::sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}
 
long long gcd_(long long a, long long b){
  if(a<b){
    std::swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}
 
//using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main(){
  using namespace std;
  int n, k;
  cin>>n>>k;
  int a[n];
  REP(i, n) cin>>a[i];
  
  int ans[n];
  REP(i, n) ans[i] = a[i];
  if(k >= 41){
    REP(i, n) cout << n << ' ';
    cout << endl;
    return 0;
  }
  REP(_, k){
    vector<int> temp(n, 0);
    REP(i, n){
      int l = max(0, i - ans[i]);
      int r = min(n - 1, i + ans[i]);
      temp[l]++;
      if(r + 1 < n) temp[r + 1]--;
    }
    REPP(i, n - 1) temp[i] += temp[i - 1];
    REP(i, n) ans[i] = temp[i];
  }
  REP(i, n) cout << ans[i] << ' ';
  cout << endl;  
  return 0;
}
