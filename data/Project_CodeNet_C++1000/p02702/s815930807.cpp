#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  string S;
  cin>>S;
  int64_t ans=0,k=S.size();
  vector<int64_t> T(2019,0);
  T.at(0)++;
  int64_t h=0,t=1;
  for(int64_t i=k-1;i>=0;i--){
    int64_t a=(S.at(i)-'0');
    h+=a*t;
    h%=2019;
    T.at(h)++;
    t*=10;
    t%=2019;
  }
  for(int64_t i=0;i<2019;i++){
    auto a=T.at(i);
    if(a>1) ans+=a*(a-1)/2;
  }
  cout<<ans;
}
