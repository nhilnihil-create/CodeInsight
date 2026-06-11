#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.size();

  s += 'R';

  int ans[n];
  for(int i=0; i<n; i++) ans[i]=0;

  int rcount = 1;
  int lcount = 0;
  bool now_r = true;
  int tmp = 0;
  for(int i=1; i<n+1; i++) {
    if(now_r) {
      if(s[i]=='R') rcount++;
      else {
        ans[i] += rcount/2;
        ans[i-1] += (rcount+1)/2;
        rcount = 0;
        lcount = 1;
        tmp = i;
        now_r = false;
      }
    }
    else {
      // if(s[i]=='L' && i!=n-1) lcount++;
      if(s[i]=='L') lcount++;
      else {
        // if(i==n-1) lcount++;
        ans[tmp] += (lcount+1)/2;
        ans[tmp-1] += lcount/2;
        lcount = 0;
        rcount = 1;
        now_r = true;
      }
    }
  }

  for(int i=0; i<n-1; i++) {
    cout<<ans[i]<<' ';
  }
  cout<<ans[n-1]<<endl;


  return 0;
}