
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  cin >> s;
  int n = s.size() + 1;
  int a[n];
  rep(i, n) a[i] = 0;
  for(int i = 0; i < n - 1; i++){
    if(s[i] == '<'){
      a[i + 1] = a[i] + 1;
    }
  }
  for(int i = n - 2; i >= 0; i--){
    if(s[i] == '>'){
      a[i] = max(a[i], a[i + 1] + 1);
    }
  }
  ll sum = 0;
  rep(i, n) sum += a[i];
  cout << sum << endl;
  return 0;
}
