#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i, N) for (int i = 0; i < N; i++)
#define REP1(i, N) for (int i = 1; i < N; i++)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ANS(a) cout << a << endl
#define SORT(V) sort(V.begin(), V.end())
#define RSORT(V) sort(V.rbegin(), V.rend())
#define DBG(V) for (auto v : V) cout << v << " "; cout << endl

int N;
vector<int> A;

int
main()
{
  cin >> N;
  int max = 0;
  int max2 = 0;
  REP(i, N) { int a; cin >> a; A.push_back(a); 
    if (max < a) { max = a; }
    else if (max2 < a) { max2 = a; }
  }

  REP(i, N) {
    if (A[i] == max) {
      printf("%d\n", max2);
    } else {
      printf("%d\n", max);
    }
  }
}
