#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

bool kaibun(string S){
  int t=S.size();
  bool K=true;
  rep(i,t){
    if(S.at(i)!=S.at(t-1-i)) K=false;
  }
  return K;
}

void YN(bool x){
  if(x) cout<<"Yes";
  else cout<<"No";
}

int main() {
  string S,s1,s2; cin>>S;
  int N=S.size();
  rep(i,(N-1)/2){
    s1.push_back(S.at(i));
    s2.push_back(S.at(i+(N+1)/2));
  }
  bool a=kaibun(s1),b=kaibun(s2);
  YN(a&&b&&s1==s2);
}
