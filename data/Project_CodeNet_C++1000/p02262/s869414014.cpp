#include <iostream>

using namespace std;

class ShellSort
{
public:
  int insertSort( int *a, int n, int g);
  int shsort( int *a, int n, int *m, int *g );
};

int ShellSort::insertSort( int *a, int n, int g)
{
  int cnt = 0;
  
  for ( int i = g; i < n; i++ )
    {
      int v = a[i];
      int j = i - g;
      while (j >= 0 && a[j] > v)
        {
          a[j+g] = a[j];
          j -= g;
          cnt++;
        }
      a[j+g] = v;
    }
  return cnt;
}

int ShellSort::shsort( int *a, int n, int *m, int *g )
{
  int cnt = 0;

  int i = 0;

  if ( n == 1 )
    {
      *m = 1;
      g[0] = 1;
    }
  else
    {
      for (int l = n / 2; l > 0; l /= 2)
        {
          (*m)++;
          g[i++] = l;
        }
    }
  
  for ( int i = 0; i < *m; i++ )
    {
      cnt += insertSort(a, n, g[i]);
    }

  return cnt;
}

int main( void )
{
  int n;
  int g[100];
  int m = 0;
  int cnt;

  ShellSort ss;

  cin >> n;

  int *a = new int[n];
  
  for ( int i = 0; i < n; i++ )
    {
      cin >> a[i];
    }

  cnt = ss.shsort(a, n, &m, g);
  
  cout << m << endl;
  cout << g[0];
  for(int i = 1; i < m; i++)
    cout << " " << g[i];
  cout << endl;

  cout << cnt << endl;
  
  for(int i = 0; i < n; i++)
    cout <<  a[i] << endl;

  return 0;
}