#include <iostream>
using namespace std;
 
int main()
{
  int n, cnt = 0;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int p;
    cin >> p;
    if(p != i + 1)
      cnt++;
  }
  cout << (cnt == 2 || cnt == 0 ? "YES" : "NO") << endl;
  return 0;
}