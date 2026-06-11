#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int M = 2019;

 

int cnt[M + 3];
 
int main() {
  ll res = 0;
  string s;
  cin>>s;
  int len = s.size(), t = 0, p = 1;
  for (int i = len - 1; i >= 0; --i) {
    ++cnt[t];
    t += (s[i] - 48) * p;
    t %= M;
    res += cnt[t];
    p = p * 10 % M;
  }
  cout<<res;
  return 0;
}
