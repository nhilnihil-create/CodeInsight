#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int mod = 1e9+7;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n,m;
  cin>>n>>m;
  char s[n][m];
  int a[n][m];
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>s[i][j];
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      a[i][j] = 1000000000;
      if(i+j==0)
        a[i][j] = (s[i][j]=='#');
      else {
        if(i > 0)
          a[i][j] = min(a[i][j],a[i-1][j]+((s[i-1][j]=='.')&&(s[i][j]=='#')));
        if(j > 0)
          a[i][j] = min(a[i][j],a[i][j-1]+((s[i][j-1]=='.')&&(s[i][j]=='#')));
      }
    }
  }
  cout<<a[n-1][m-1];
  cout<<"\n";
  return 0;
}