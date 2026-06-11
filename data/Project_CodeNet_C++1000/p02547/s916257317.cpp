#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,cnt=0; cin >>n;
  bool three = false;
  rep(i,n){
    int a,b; cin >>a >>b;
    if(a==b) cnt++;
    else cnt=0;
    if(cnt==3) three = true;
  }
  if(three) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}