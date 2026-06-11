#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  if(n >= 3200){
    cout << s << endl;
  }
  else {
    cout << "red" << endl;
  }
  return 0;
}