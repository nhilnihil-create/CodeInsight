#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  M mp;
  rep(i, n - 1){
    int x;
    cin >> x;
    mp[x]++;
  }
  rep(i, n){
    cout << mp[i + 1] << endl;
  }

  return 0;
}
