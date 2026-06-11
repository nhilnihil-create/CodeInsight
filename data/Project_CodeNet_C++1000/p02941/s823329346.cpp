#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
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
using namespace std;
//using namespace boost::multiprecision;

bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
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


int main(){
  
  int n;
  cin>>n;
  int a[n],b[n];
  REP(i,n){
    cin>>a[i];
  }
  REP(i,n){
    cin>>b[i];
  }
  priority_queue<pair<int, int>> q;
  REP(i,n){
    q.push(make_pair(b[i],i));
  }
  long long ans = 0;
  while(!q.empty()){
    int val = q.top().first;
    int i = q.top().second;
    q.pop();
    if(val == a[i]){
      continue;
    }
    if(val < a[i]){
      cout<<-1<<endl;
      return 0;
    }
    int l = i - 1, r = i + 1;
    if(l < 0){
      l = n - 1;
    }
    if(r >= n){
      r = 0;
    }
    long long cnt;
    cnt = (b[i] - a[i])/(b[l] + b[r]);
    if(cnt == 0){
      cout<<-1<<endl;
      return 0;
    }
    ans += cnt;
    b[i] -= cnt*(b[l] + b[r]);
    q.push(make_pair(b[i],i));
  }
  cout<<ans<<endl; 
  return 0; 
}
