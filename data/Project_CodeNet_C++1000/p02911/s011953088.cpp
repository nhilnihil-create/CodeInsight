#include<iostream>
#include<vector>
#define rep(i, n) for(int i = 0; i < (n); i ++)
using namespace std;

int main()
{
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> p(n, 0);
  
  int a;
  rep(i, q)
  {
    cin >> a;
    a --;
    p.at(a) ++;
  }
  
  rep(i, n)
  {
    if (p.at(i) + k - q > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  return 0;
}