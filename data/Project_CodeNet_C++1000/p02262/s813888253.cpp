#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int cnt = 0;
int insertionsort(vector<int>& vi, int n, int g)
{
  for(int i=g; i<n; i++) // for each g times loop , each group adds one int;
  {
    int v = vi[i];
    int j = i-g; // must't plus 1
    while(j>=0 && vi[j] > v)// greater int goes to behind;
    {
      vi[j+g] = vi[j]; //g as interval
      j -= g;
      cnt++;
    }
    vi[j+g] = v;
  }
  return 0;
}

int shellsort(vector<int>& vi, int n)
{
  int m = 1;
  vector<int> G;
  G.push_back(1);
  while(1)
  {
    if(3*G[m-1]+1 < n)
    {
      G.push_back(3*G[m-1]+1);
      m++;
    }
    else break;
  }
  cout << m << endl;
  for(int i=m-1; i>=0; i--)
  {
    if(i!=m-1) cout << " ";
    cout << G[i] ;
  }
  cout << endl;
  for(int i=m-1; i>=0; i--)
  {
    insertionsort(vi, n, G[i]);
  }
  cout << cnt << endl;
  for(int i=0; i<n; i++)
  {
    cout << vi[i] << endl;
  }
  return 0;
}
int main()
{
  int n;
  cin >> n;
  vector<int> vi;
  for(int i=0; i<n; i++)
  {
    int temp;
    cin >> temp;
    vi.push_back(temp);
  }
  shellsort(vi, n);
  return 0;
}

