#include <iostream>
using namespace std;

int main()
{
  int n, k, q;
  cin >> n >> k >> q;
  int correct[n] = {0};
  for(int i = 0; i < q; ++i)
  {
    int c;
    cin >> c;
    correct[c-1]++;
  }
  
  for(int i = 0; i < n; ++i)
  {
    bool ans = k - (q - correct[i]) > 0;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}