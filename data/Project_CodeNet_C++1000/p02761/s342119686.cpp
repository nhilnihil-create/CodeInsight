#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    int N,M; cin >> N >> M;
    vector<char> S(N,'.');
    vi s(M);
    vector<char> c(M);
    rep(i,M) cin>>s[i]>>c[i];
  
    bool flag=true;
  
    rep(i,M){
      if(S[s[i]-1]=='.'|| S[s[i]-1]==c[i] ){
        S[s[i]-1]=c[i];
      }else{
        flag = false;
      }
    }
    if(S[0] == '0'&&N!=1) flag = false;
    rep(i,N){
      if( S[i]=='.') {
        if(N!=1&&0==i)
          S[i]='1';
        else
          S[i]='0';
      }
      
    }
    
  
    if(flag) rep(i,N)cout<< S[i];
    else cout<<-1;
    return 0;
}
