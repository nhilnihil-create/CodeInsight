#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;

  cin >> n;

  int flag = 0;

  vector<int> a(n+1);

  rep(i,n){
    cin >> a.at(i);
  }

  sort(a.begin(),a.end());

  rep(i,n){
    if(a.at(i) == a.at(i+1))
    flag = 1;
  }

  if(flag == 1)
  cout << "NO";
  
  else
  {
    cout << "YES";
  }
  
  
}