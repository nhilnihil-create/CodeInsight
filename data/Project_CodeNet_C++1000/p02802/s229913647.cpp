#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll N,M;
  cin >> N >> M;
  vector<ll> ans1(N,0),ans2temp(N,0),ans2(N,0),p(M);
  vector<bool>flag(N,0);
  vector<string> S(M);
  rep(i,M) {
    cin >> p[i] >> S[i];
    if(flag[p[i]-1]==0){
      if(S[i]=="WA") ans2temp[p[i]-1]++;
      else {
        ans1[p[i]-1]=1;
        ans2[p[i]-1]=ans2temp[p[i]-1];
        flag[p[i]-1]=1;
     }
    }
  }
  
  cout << accumulate(ans1.begin(), ans1.end(), 0) << " " << accumulate(ans2.begin(), ans2.end(), 0) << endl;
  return 0;
}