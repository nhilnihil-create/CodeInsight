#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  double border = 0;
  vector<int> a;
  
  cin >> n >> m;
  for(int i=0; i<n; i++)
  {
    int t;
    cin >> t;
    border += t;
    a.push_back(t);
  }
  
  border /= 4 * m;
  int cnt = 0;
  for(int i=0; i<n; i++)
  {
    if(a[i] >= border)
      cnt++;
    if(cnt >= m)
      break;
  }
  cout << (cnt >= m ? "Yes" : "No") << endl;
  return 0;
}