#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  cin >> n;

  vector<int> a(n-1);

  vector<int> b(n);

  rep(i, n-1)
  {
    cin >> a.at(i);
  }

  rep(i,n-1){
    b.at(a.at(i)-1) += 1;
  }

  rep(i,n){
    cout << b.at(i) << endl;
  }
}
