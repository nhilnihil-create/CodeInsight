#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  int ans=0;
  int cnt=0;
  int temp=0;
  for(int i=N;i>0;--i){
    temp=i;
    while(1){
      cnt++;
      temp=temp/10;
      if(temp==0) break;
    }
    if(cnt%2==1) ans++;
    cnt=0;
  }
  cout << ans << endl;
}