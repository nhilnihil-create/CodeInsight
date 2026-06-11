#include <bits/stdc++.h>
using namespace std;

int main()
{
 int n;
  cin >> n;
  
  string as[100] = {};
  int ai[100] = {};
  for (int i = 0;i < n;i++)
	cin >> as[i] >> ai[i];
  
  string x;
  cin >> x;
  int sum = 0;
  bool f = false;
  for (int i = 0;i < n;i++)
  {
    if (f)
      sum+= ai[i];

   if (as[i] == x) {

     f=true;
   }
  
  }
  cout << sum << endl;
}
