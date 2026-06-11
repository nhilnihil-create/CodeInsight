#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i <= 1e7; i++) 
    if(i * 108/100 == n)
      return cout << i, 0;
  cout << ":(";

    

  
}

