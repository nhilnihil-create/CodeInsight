#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)
int main(){
  int n,x;	cin >> n >> x;
  int len=0;
  int ans=1;
  rep(i,n){
    int l;	cin >> l;
    len+=l;
    if(len>x)	continue;
    ans++;
  }
  cout << ans;
}