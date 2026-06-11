#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
#define outl(x) cout<< (x) << '\n'
#define pb push_back

long long cnt = 0;
int N;
int a[1000005];
vector<int> G;

void insertionSort(int g);
void shellSort();

int main()
{
   cin.tie(0), ios::sync_with_stdio(false);

   cin >> N;
   rep(i, N)cin >> a[i];

   shellSort();

   outl( G.size() );

   for(int i=G.size()-1; i>=0; --i)
      cout << G[i] << (i? ' ' : '\n');

   outl(cnt);

   rep(i, N)
      outl(a[i]);
}

void insertionSort(int g)
{
   for(int i=g; i<N; ++i){
      int v= a[i];
      int j= i - g;
      while( j >= 0 && a[j] > v ){
         a[j+g] = a[j];
         j -= g;
         ++cnt;
      }
      a[j+g] = v;
   }
}

void shellSort()
{
   cnt = 0;
   for(int g = 1; g <= N; g = 3*g + 1)
      G.pb(g);

   for(int i=G.size()-1; i >= 0; --i){
      insertionSort(G[i]);
   }
}


