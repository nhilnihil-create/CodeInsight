#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  string s; cin >> s;
  int n = s.size();
  int ans[n];
  memset(ans,0,sizeof(ans));
  for(int i=0;i<n;i++){
    if(s[i]=='R'){
      int k=0;
      while(s[i+k]=='R') k++;
      int x = i+k;
      int y = k/2;
      ans[x] += y;
      ans[x-1] += y+k%2;
      i += k-1;
    }else{
      int k=0;
      while(s[i+k]=='L') k++;
      int x = i-1;
      int y = k/2;
      ans[x] += y;
      ans[x+1] += y+k%2;
      i += k-1;
    } 
  }
  
  for(int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
  
}
