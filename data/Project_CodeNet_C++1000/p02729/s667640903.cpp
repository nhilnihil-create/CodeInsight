#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

void YN(bool x){
  if(x) cout<<"Yes";
  else cout<<"No";
}

int main() {
  int A,B,C,D; cin>>A>>B>>C>>D;
  cout<<A*(A-1)/2+B*(B-1)/2;
}
