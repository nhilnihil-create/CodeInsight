#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  ll N; cin >>N;
  deque<char> ans;
  while (N>0) {
    N--;
    char a='a'+(N%26);
    ans.push_front(a);
    N/=26;
  }
  rep(i,0,ans.size()) {cout <<ans[i];}
  return 0;
}
