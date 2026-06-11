#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  while(1){
    int a,d,n;
    cin >> a >> d >> n;
    if(n==0) return 0;
    int x;
    int count=0;
    for(int i=0;1;i++){
      x=a+d*i;
      for(int j=2;j<=sqrt(x);j++){
        if(x%j==0){
          goto next;
        }
      }
      if(x>1) count++;
      if(count==n){
        cout << x << endl;
        break;
      }
      next:
      continue;
    }
  }
  return 0;
}

