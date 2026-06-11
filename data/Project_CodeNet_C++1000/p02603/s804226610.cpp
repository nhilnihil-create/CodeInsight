#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
typedef long long ll;
template<class T>bool input(T &t){int n=1,c;for(t=0;!isdigit(c=getchar())&&~c&&c-45;);
if(!~c)return 0;for(c-45&&(n=0,t=c^48);isdigit(c=getchar());)t=10*t+c-48;t=n?-t:t;return 1;}
template<class S,class ...T>bool input(S&a,T&...t){input(a);return input(t...);}
template<class T>bool inputs(T *a, int n) { REP(i,n) if(!input(a[i])) return 0; return 1;}

int A[80];

int main() {
  int n;
  while (cin>> n) {
    inputs(A,n);
    ll cur = 1000;
    ll cur2 = 0;
    REP(i,n-1) {
      if (A[i]<A[i+1]) {
        ll t = cur / A[i];
        cur -= A[i] * t;
        cur2 += t;
      }
      else if (A[i]>A[i+1]) {
        cur += A[i] * cur2;
        cur2 = 0;
      }
    }
    cout << cur + cur2 * A[n-1] << endl;
  }
}
