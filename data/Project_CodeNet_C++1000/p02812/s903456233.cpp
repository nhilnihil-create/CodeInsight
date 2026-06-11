#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans=0;
  string T="ABC";
  rep(i,N-T.size()+1){
    int cnt=0;
     rep(j,3) {
      if(S[i+j]==T[j]){
        cnt++;
      }
      if(cnt==3) ans++;
    }
  }
  cout << ans << endl;
}
