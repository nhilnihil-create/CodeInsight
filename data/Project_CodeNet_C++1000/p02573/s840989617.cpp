#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

class UnionFind
{
public:
   vector<int> parent;
   UnionFind(int N)
   {
      for (int i = 0; i < N; i++)
      {
         parent.push_back(-1);
      }
   }
   int root(int A)
   {
      if (parent[A] < 0)
         return A;
      return parent[A] = root(parent[A]);
   }
   int size(int A)
   {
      return -parent[root(A)];
   }

   bool unite(int A, int B)
   {
      A = root(A);
      B = root(B);
      if (A == B)
         return false;
      if (size(A) < size(B))
         swap(A, B);
      parent[A] += parent[B];
      parent[B] = A;
      return true;
   }
};

int main(void)
{
   int N, M;
   cin >> N >> M;
   vector<int> A(M), B(M);
   UnionFind UF(N);
   for (int i = 0; i < M; i++)
   {
      cin >> A[i] >> B[i];
      A[i]--;
      B[i]--;
   }
   for (int i = 0; i < M; i++)
   {
      UF.unite(A[i], B[i]);
   }
   int ans = 0;
   for (int i = 0; i < N; i++)
   {
      ans = max(ans, UF.size(i));
   }
   cout << ans << endl;
   return 0;
}
