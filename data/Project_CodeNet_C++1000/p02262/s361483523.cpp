#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

void inseSort(int A[],int n, int g)
{
  for(int i=g; i<n; i++)
  {
    int v = A[i];
    int j = i-g;
    while(j>=0 && A[j] > v)
    {
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shell(int A[], int n)
{
  for(int h=1; ;)
  {
    if(h>n) break;
    G.push_back(h);
    h = 3*h + 1;
  }
  for(int i=G.size()-1; i>=0; i--)
  {
    inseSort(A, n, G[i]);
  }
}

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }
  cnt = 0;
  shell(A, n);
  printf("%d\n", G.size());
  for(int i=G.size()-1; i>=0; i--)
  {
    printf("%d", G[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n", cnt);
  for(int i=0; i<n; i++)
  {
    printf("%d\n", A[i]);
  }

  return 0;
}

