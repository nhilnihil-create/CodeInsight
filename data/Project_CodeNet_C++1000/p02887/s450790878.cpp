#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  int n,ans;
  string s;
  char a,b;
  cin>>n>>s;
  ans=n;
  a=s[0];
  rep(i,n-1){
    b=s[i+1];
    if(a==b) ans--;
    else a=b;
  }
  cout<<ans;
}