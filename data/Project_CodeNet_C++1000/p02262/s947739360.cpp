#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int cnt, m = 0;

void insertionSort(int A[], int n, int g)
{
  for(int i = g, v, j; i < n; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j + g] = A[j];
      j -= g;
      if(cnt < ceil(pow((double)n, 1.5)) - 1)
	cnt++;
      A[j + g] = v;
    }
  }
}

void shellSort(int A[], int G[], int n)
{
  cnt = 0;
  for(int i = 0; i < m; i++)
    insertionSort(A, n, G[i]);
}

int main()
{
  int n, c = 0;
  cin >> n;
  int A[n];
  for(int i = 0; i < n; i++)
    cin >> A[i];
  for(int i = 0; m < n; i++, c++)
    m = m * 3 + 1;
  m = c - 1;
  m = (m < 1) ? 1 : m;
  int G[m];
  for(int i = 0; i < m; i++)
    if(i)
      G[i] = G[i - 1] * 3 + 1;
    else 
      G[i] = 1;
  reverse(G, G + m);
  shellSort(A, G, n);
  cout << m << endl;
  for(int i = 0; i < m; i++)
    if(i)
      cout << " " << G[i];
    else 
      cout << G[i];
  cout << endl << cnt << endl;
  for(int i = 0; i < n; i++)
    cout <<  A[i] << endl;
}