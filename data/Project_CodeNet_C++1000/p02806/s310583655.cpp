#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
const ll MOD = 998244353;
int T[55];
string S[55];
int main(){
  int n;cin >>n;
  for(int i=1;i<=n;i++){
    cin>>S[i]>>T[i];
  }
  string x;cin>>x;
  int off=0;
  int ans=0;
  for(int i=2;i<=n;i++){
    if(S[i-1]==x)off++;
    if(off==1)ans+=T[i];
  }
  cout<<ans<<endl;
}
