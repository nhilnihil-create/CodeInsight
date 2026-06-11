#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  string S; cin >> S;
  int N = S.size();
  int a[N] = {};

  // 左から見る
  int cnt[2]={};
  int j = 0;
  rep(i,N){
    if (S[i]=='R') {
      cnt[j%2]++;
      j++;
    }
    if (i+1<N && S.substr(i,2)=="RL" && j>0){
      a[i] += cnt[(j+1)%2];
      a[i+1] += cnt[j%2];
      j=0;
      cnt[0] = 0;
      cnt[1] = 0;
    }
  }
  cnt[0]=0, cnt[1]=0;
  j=0;
  rep(i,N){
    if (S[N-1-i]=='L') {
      cnt[j%2]++;
      j++;
    }
    if (N-i-2>=0 && S.substr(N-2-i,2)=="RL" && j>0){
      a[N-2-i] += cnt[j%2];
      a[N-1-i] += cnt[(j+1)%2];
      j=0;
      cnt[0] = 0;
      cnt[1] = 0;
    }
  }
  rep(i,N) {
    if (i>0) cout << " ";
    cout << a[i];
  }

  // cout << fixed << setprecision(10);
  
  return 0;
}
