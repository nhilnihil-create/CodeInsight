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
  if(n == 1){
    cout<<"No"<<endl;
    return 0;
  }
  REPP(i,20){
    if(n == (1<<i)){
      cout<<"No"<<endl;
      return 0;
    }
  }
  if(n%2 == 1){
    cout<<"Yes"<<endl;
    cout<<3<<' '<<n+1<<endl;
    REPP(i,2){
      cout<<i<<' '<<i+1<<endl;
      cout<<n+i<<' '<<n+i+1<<endl;
    }
    for(int i = 4; i<n; i+=2){
      cout<<i<<' '<<i+1<<endl;
      cout<<i+1<<' '<<n+1<<endl;
      cout<<n+1<<' '<<n+i<<endl;
      cout<<n+i<<' '<<n+i+1<<endl;
    }
  }else{
    cout<<"Yes"<<endl;
    cout<<3<<' '<<n+1<<endl;
    REPP(i,2){
      cout<<i<<' '<<i+1<<endl;
      cout<<n+i<<' '<<n+i+1<<endl;
    }
    for(int i = 4; i<n; i+=2){
      cout<<i<<' '<<i+1<<endl;
      cout<<i+1<<' '<<n+1<<endl;
      cout<<n+1<<' '<<n+i<<endl;
      cout<<n+i<<' '<<n+i+1<<endl;
    }
    int msb;
    for(int i = 20; i>=0; i--){
      if((n+1) & (1<<i)){
        msb = i;
        break;
      }
    }
    int a = (1<<msb);
    int b = a^(n + 1);
    cout<<a+n<<' '<<n<<endl;
    cout<<b<<' '<<2*n<<endl;
  }
  return 0; 
}
