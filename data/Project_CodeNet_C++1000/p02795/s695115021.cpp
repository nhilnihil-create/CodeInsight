#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int h,w,n;
  cin>>h>>w>>n;
  h=max(h,w);
  int ans=0;
  int black=0;
  while(black<n){
    ans++;
    black+=h;
  }
  cout<<ans<<endl;
}