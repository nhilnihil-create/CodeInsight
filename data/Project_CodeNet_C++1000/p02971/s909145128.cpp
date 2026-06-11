#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i)
  {
    int num;
    cin >> num;
    a[i] = num;
    b[i] = num;
  }

  sort(a.begin(), a.end());
  int max = a[n-1];
  int next;
  bool dup = false;
  for(int i = n-2; i >=0; --i)
  {
    if(a[i] == max)
    {
      dup = true;
    }
    else
    {
      next = a[i];
      break;
    }
  }
  
  for(int i = 0; i < n; ++i)
  {
    if(b[i] != max)
    {
      cout << max << endl;
    }
    else
    {
      if(dup) cout << max << endl;
      else cout << next << endl;
    }
  }
}