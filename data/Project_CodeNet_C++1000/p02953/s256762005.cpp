#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int h[n];
  rep(i,n)cin >> h[i];

  string ans="Yes";
  for(int i=n-1;i>1;i--){
    if(h[i]<h[i-1])
      if(h[i]<h[i-1]-1){
	ans="No";
	break;
      }else h[i-1]--;
  }
  cout << ans << endl;
}
