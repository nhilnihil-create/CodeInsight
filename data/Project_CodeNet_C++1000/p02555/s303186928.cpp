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

int S;
int c[N];

int main(){
  scanf("%d", &S);
  
  if(S < 3){
    printf("0\n");
    return 0;
  }
  
  c[0] = 1;
  for(int i = 3; i <= S; i++){
    for(int j = 3; j <= i; j++)
      c[i] = add(c[i], c[i - j]);
  }

  printf("%d\n", c[S]);
  
  return 0;
}
