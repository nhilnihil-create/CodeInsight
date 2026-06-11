#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N; cin>>N;
  if(N%2==1) cout<<0;
  else{
    int64_t ans=0;
    ans+=N/10;
    N/=10;
    while(N>=5){
      N/=5;
      ans+=N;
    }
    cout<<ans;
  }
}
