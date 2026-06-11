#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
     cin >> a.at(i);
  }
  for (int j = 0; j < k; j++)
  {
     vector<int> b(n+1);
     for (int i = 0; i < n; i++)
     {
        int l = max(0, i-a.at(i));
        int r = min(i+a.at(i)+1, n);
        b.at(l)++;
        b.at(r)--;
     }
     for (int i = 0; i < n; i++)
     {
        b.at(i+1) += b.at(i);
     }
     b.pop_back();
     if (a == b)
     {
        break;
     }
     a = b;
     
  }
  for (int i = 0; i < n; i++)
  {
     cout << a.at(i) << endl;
  }
  
   
  return 0;
}