#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, k, q;
  cin >> n >> k >> q;
  int a[n];
  rep(i, n) a[i] = 0;
  int x;
  rep(i, q){
    cin >> x;
    a[x - 1]++;
  }
  rep(i, n){
    if(q - a[i] < k) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}