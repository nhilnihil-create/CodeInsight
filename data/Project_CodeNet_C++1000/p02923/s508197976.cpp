#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int max_combo = 0;
  int combo = 0;
  
  int prev;
  cin >> prev;
  int tmp;
  for (int i = 1; i < n; i ++)
  {
    cin >> tmp;
    if (prev >= tmp)
    {
      combo ++;
      if (combo > max_combo) max_combo = combo;
    }
    else combo = 0;
    prev = tmp;
  }
  
  cout << max_combo;
  return 0;
}
