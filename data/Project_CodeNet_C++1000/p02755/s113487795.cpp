#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int A,B;cin>>A>>B;
  bool flag=true;
  rep(i,1001){
    if(int(i*0.08)==A && int(i*0.1)==B){
      flag=false;
      cout<<i<<endl;
      break;
    }
  }
  if(flag) cout<<-1<<endl;
}