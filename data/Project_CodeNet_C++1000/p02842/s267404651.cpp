#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ,X ;
  bool a=false;
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    if (i*108/100 == N)
    {
     a=true;
     cout << i <<endl;
     break;
    }
     
  }
  if (a == false)
  {
    cout << ":(" << endl;
  }
  
  
  return 0;
}