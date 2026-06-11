#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll k;
  cin >> k;
  ll na=7;
  rep(i,1e6+1){
    na%=k;
    if(na==0){
      cout << i+1;
      return 0;
    }
    na=na*10+7;
  }
  cout << -1;
  
}
    