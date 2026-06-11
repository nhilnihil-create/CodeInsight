#include <bits/stdc++.h>
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
using namespace std;

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
  int cnt[n] = {};
  REP(i,n){
    int a;
    cin>>a;
    a--;
    cnt[a]++;
  }
  vector<int> a;
  REP(i,n){
    if(cnt[i] == 0)continue;
    a.push_back(cnt[i]);
  }
  sort(ALL(a));
  
  int m = a.size();
  int s[m];
  REP(i,m){
    if(i==0){
      s[i] = a[i];
    }else{
      s[i] = s[i-1] + a[i];
    }
  }
  REPP(k,n){
    //[l,r)上での二分探索
    int l = 0;
    int r = n/k + 1;
    while(r-l>1){
      int t = (l+r)/2;
      int num = lower_bound(ALL(a), t) - a.begin();//t未満の値を持つaの要素の個数
      int temp;
      if(num == 0){
        temp = t*m;
      }else{
        temp = s[num-1] + t*(m-num);
      }
      if(temp >= t*k){
        l = t;
      }else{
        r = t;
      }
    }
    cout<<l<<endl;
  }
  return 0; 
}
