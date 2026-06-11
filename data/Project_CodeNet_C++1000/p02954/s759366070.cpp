#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ans(n,0);
  for(int i=0; i<n; ++i){
    if(s[i] == 'L') continue;
    int odd = 0, even = 0;
    bool frag = true;
    while(i<n && s[i] == 'R'){
      if(frag){
        ++odd;
        frag = false;
      }else{
        ++even;
        frag = true;
      }
      ++i;
    }
    ans[i] += (frag ? odd:even);
    ans[i-1] += (frag ? even:odd);
  }
  for(int i=n-1; i>=0; --i){
    if(s[i] == 'R') continue;
    int odd = 0, even = 0;
    bool frag = true;
    while(i>=0 && s[i] == 'L'){
      if(frag){
        ++odd;
        frag = false;
      }else{
        ++even;
        frag = true;
      }
      --i;
    }
    ans[i] += (frag ? odd:even);
    ans[i+1] += (frag ? even:odd);
  }
  for(int i=0; i<n; ++i){
    if(i != n-1) printf("%d ",ans[i]);
    else printf("%d\n",ans[i]);
  }
}