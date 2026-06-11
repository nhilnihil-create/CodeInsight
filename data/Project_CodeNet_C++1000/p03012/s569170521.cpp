#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
  int n, t, threshold = 0;
  cin >> n;
  vector<int> w(n);
  for(int i=0; i<n; i++)
  {
    cin >> w[i];
    threshold += w[i];
  }
  
  threshold = (threshold + 1) / 2;
  
  int s1 = 0;
  for(int i=0; i<n; i++)
  {
    s1 += w[i];
    
    if(s1 > threshold)
    {
      if(abs(s1 - w[i] - threshold) < abs(s1 - threshold))
      {
        s1 -= w[i];
        t = i;
        break;
      }
      else
      {
        t = i + 1;
        break;
      }
    }
  }
  int s2 = accumulate(w.begin() + t, w.end(), 0);
  cout << abs(s1 - s2) << endl;
  return 0;
}