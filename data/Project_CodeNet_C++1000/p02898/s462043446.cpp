#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  int a,b,ans=0,c;
  cin>>a>>b;
  rep(i,a){
    cin>>c;
    if(c>=b) ans++;
  }
  cout<<ans;
  return 0;
}
