#include <bits/stdc++.h>
 
#define TRACE(x) cerr << #x << " = " << x << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define SZ(x) (int)(x).size()
 
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> pii;
 
template<class Num>
Num mabs(Num A){
  if(A < 0) return -A;
  return A;
}

const int N = 2005, mod = 1e9 + 7;

inline int add(int a, int b){
  int ret = a + b;
  if(ret >= mod) ret -= mod;
  return ret;
}

inline int sub(int a, int b){
  int ret = a - b;
  if(ret < 0) ret += mod;
  return ret;
}

int n;

int main(){
  scanf("%d", &n);
    
  int des = 1, dev = 1, os = 1;
  for(int i = 1; i <= n; i++){
    des = (ll)des * 10ll % mod;
    dev = (ll)dev * 9ll % mod;
    os = (ll)os * 8ll % mod;
  }
  
  dev = (ll)dev * 2ll % mod;
  
  int ans = sub(des, dev);
  ans = add(ans, os);
  
  printf("%d\n", ans);
  
  return 0;
}
