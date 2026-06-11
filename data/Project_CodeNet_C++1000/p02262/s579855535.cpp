#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

// Insertion sort with interval g
void Insertion_sort(int A[], int n, int g)
{
  for (int i = g; i < n; ++i)
  {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v)
    {
      A[j + g] = A[j];
      j -= g;
      ++cnt;
    }
    A[j + g] = v;
  }
}

void shell_sort(int A[], int n)
{
  // Genarate G = {1, 4, 13, 40, 121, 364, 1093, ...}
  int g_i = 1;
  while (true)
  {
    if (g_i > n) break; // Interval is never greater than n
    G.push_back(g_i);     // Add G[i]
    g_i = 3 * g_i + 1;  // G[i + 1] = 3 * G[i] + 1
  }

  // Specify G[i] in reverse order
  for (int i = G.size() - 1; i >= 0; --i)
  {
    // Excute insertion sort with interval G[i]
    Insertion_sort(A, n, G[i]);
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
  cnt = 0;

  shell_sort(A, n);

  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; --i)
  {
    printf("%d", G[i]);
    if (i) printf(" "); // If n !=0 then add a white space
  }
  printf("\n");
  printf("%lld\n", cnt);
  for (int i = 0; i < n; ++i) printf("%d\n", A[i]);

  return 0;
}

