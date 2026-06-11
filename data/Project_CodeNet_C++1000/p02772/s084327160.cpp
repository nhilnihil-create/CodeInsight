#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  cin >> n;

  bool flag = true;

  vector<int> a(n);
  rep(i, n){
    cin >> a.at(i);
    if(a.at(i) %2 == 0){
      if(a.at(i) %3 != 0 && a.at(i) % 5 !=0){
        flag = false;
      }
    }
  }

  if(flag)
    cout << "APPROVED";
  else
  {
    cout << "DENIED ";
  }

}
