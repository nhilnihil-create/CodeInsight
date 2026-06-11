#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  long keta = 0;
  long nn = n;
  rep(i,1000){
    if(nn<=pow(26,i+1)){
      keta = i+1;
      break;
    }
    nn -= pow(26,i+1);
  }
  int i = 1;
  while(n>pow(26,i)){
    n -= pow(26,i);
    i++;
  }
  n -= 1;
  string ans;
  rep(j,keta){
    ans.push_back('a'+n%26);
    n /= 26;
  }
  rep(i,int(ans.size()))cout << ans[int(ans.size())-1-i];
  return 0;
}