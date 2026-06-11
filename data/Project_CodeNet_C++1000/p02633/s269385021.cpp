#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 1; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000000;
//------------------------------------------//

int main(){
  int x;cin>>x;
  rep(i,361){
    if(i*x%360==0){
      cout<<i<<endl;
      break;
    }
  }
}