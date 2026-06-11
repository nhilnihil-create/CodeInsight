#include <bits/stdc++.h>
 
#define TRACE(x) cerr << #x << " = " << x << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define SZ(x) (int)(x).size()
 
using namespace std;
 
typedef long long ll;
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

int a, b, c, d;
set<ll> S;

int main(){
  scanf("%d %d %d %d", &a, &b, &c, &d);
  
  S.insert((ll)a * c);
  S.insert((ll)a * d);
  S.insert((ll)b * c);
  S.insert((ll)b * d);
  
  printf("%lld\n", *S.rbegin());
  
  return 0;
}
