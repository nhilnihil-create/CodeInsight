#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;
  vector<int> work(n,-1);
  int cnt = 0;
  for(int i=0; i<n; ++i){
    if(s[i] == 'o'){
      ++cnt;
      work[i] = cnt;
      if(cnt == k) break;
      i += c;
    }
  }
  vector<int> ans(0);
  for(int i=n-1; i>=0; --i){
    if(s[i] == 'o'){
      if(work[i] == cnt) ans.push_back(i+1);
      --cnt;
      if(cnt == 0) break;
      i -= c;
    }
  }
  reverse(ans.begin(),ans.end());
  for(int a: ans){
    printf("%d\n",a);
  }
}