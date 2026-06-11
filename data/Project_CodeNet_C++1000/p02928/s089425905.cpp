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

// ランレングス圧縮(Run Length Encoding)
vector<pair<char,int>> RLE(string S){
  vector<pair<char,int>> p;
  int N = S.size();
  for (int i=0;i<N;i++) {
    if (S[i]==S[i+1]){
      int cnt = 1;
      char c = S[i];
      while (i+1<N && S[i]==S[i+1]) {
        i++;
        cnt++;
      }
      p.push_back({c,cnt});
    }
    else p.push_back({S[i],1});
  }

  return p;
}

int main(){
  ll N, K; cin >> N >> K;
  int a[N]; rep(i,N) cin >> a[i];

  int c[N]={}, d[N]={};
  rep(i,N){
    rep(j,N){
      if (j==i) continue;
      if (j>i && a[i]>a[j]) c[i]++;
      else if (j<i && a[i]>a[j]) d[i]++;
    }
  }
  ll retval = 0;
  ll MOD = 1000000007;
  rep(i,N){
    ll c1 = ((K+1)*K/2)%MOD, c2 = ((K-1)*K/2)%MOD;
    retval += c1*c[i] + c2*d[i];
    retval %= MOD;
  }
  cout << retval << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}
