#include<bits/stdc++.h>
using namespace std;

int main() {
  string s, t, r;
  int a, b;
  cin>>s>>t;
  map<string, int> cnt;
  cin>>a>>b;
  cnt[s] = a, cnt[t] = b;
  cin>>r;
  cnt[r]--;
  cout<<cnt[s]<<' '<<cnt[t];
}
