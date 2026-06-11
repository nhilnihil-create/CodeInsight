#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for((i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;

const double EPS = 1e-10;

const int N = 10000;
int a[N];
int n;

bool is_prime(int k) {
  for (int i=2; i*i<=k; i++)
  if (k%i == 0) return false;
  return k != 1;
}

int main() {
  int i;
  int res = 0;
  scanf("%d ", &n);
  for (i=0; i<n; i++) {
    scanf("%d ", a+i);
    if (is_prime(a[i])) res++;
  }

  printf("%d\n", res);

  return 0;
}