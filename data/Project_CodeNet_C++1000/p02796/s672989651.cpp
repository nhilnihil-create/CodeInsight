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
   int N;
   cin >> N;
   vector<int> X(N), L(N);
   vector<pair<int, int>> robot;
   for (int i = 0; i < N; i++)
   {
      cin >> X[i] >> L[i];
      robot.push_back({X[i] + L[i], X[i] - L[i]});
   }
   sort(robot.begin(), robot.end());
   int now = -1000000007;
   int ans = 0;
   for (int i = 0; i < N; i++)
   {
      if (robot[i].second >= now)
      {
         ans++;
         now = robot[i].first;
      }
   }
   cout << ans << endl;
   return 0;
}
