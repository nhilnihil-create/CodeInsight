#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  string s; cin >> s;
  int n = s.size();
  ll d[n+1][13];
  ll mod = 1e9+7;
  memset(d,0,sizeof(d));
  d[0][0] = 1;

  for(int i=1;i<=n;i++){
    char c = s[i-1];
    for(int j=0;j<10;j++){
      if(c=='?'||j==c-'0'){
        for(int k=0;k<13;k++){
          d[i][(10*k+j)%13] += d[i-1][k];
          d[i][(10*k+j)%13] %= mod;
        }
      }      
    }
  }
  cout << d[n][5] << endl;
}
