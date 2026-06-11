#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
//------------------------------------------//

int main(){
  int K,X;cin>>K>>X;
  int cnt=X-K+1;
  
  while(cnt<X+K){
    cout<<cnt<<" ";
    cnt++;
  }
}