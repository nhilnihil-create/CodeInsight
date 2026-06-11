#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define repeat(i, x) for (register ll i = 0; i < x; i++)

class DisjointSet
{
public:
  vector<int> parent;

  DisjointSet(int n) : parent(n)
  {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  void join(int a, int b)
  {
    parent[findSet(b)] = findSet(a);
  }

  int findSet(int a)
  {
    return a == parent[a] ? a : parent[a] = findSet(parent[a]);
  }

  bool same(int a, int b)
  {
    return findSet(a) == findSet(b);
  }
};

int main(void)
{
  int N, M;

  cin >> N >> M;
  int result = N - 1;

  DisjointSet disjointSet(N);

  for (int i = 0; i < M; i++)
  {
    int A, B;
    cin >> A >> B;
    A--;
    B--;

    if (!disjointSet.same(A, B))
    {
      disjointSet.join(A, B);
      result--;
    }
  }

  cout << result << endl;

  return 0;
}