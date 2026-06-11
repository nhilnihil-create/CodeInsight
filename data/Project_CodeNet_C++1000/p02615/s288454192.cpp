#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

int A[200005];

int main() {
  int n;
  S(n);
  rep(i,0,n) {
    S(A[i]);
  }
  sort(A,A+n);
  reverse(A,A+n);
  LL ans = -A[0];
  int j = 0;
  rep(i,0,n) {
    ans += A[j];
    if(i&1) j++;
  }
  cout << ans << "\n";
  return 0;
}
