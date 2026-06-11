#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(i = 0; i < n; i++)
//2D::rep(i,j)rep(j,j)cin>>bin[i][j];
//vector<int> a(n)
#define Graph vector<vector<int>>
#define A1 cout<<"No"<<endl
#define A2 cout<<"Yes"<<endl
#define A3 cout<<ans<<endl
#define AA(i) cout<<i<<endl;
const int U=2e5+5;
const ll MOD=1000000007;
const int INF = 1001001001;

int main(){
  string S,T; cin >> S;
  int i, j, k, Q; cin >> Q;
  char l;
  bool d=true;
  rep(i,Q){
    cin >> j;
    if(d){
      if(j == 1){
        d = false;
      }
      else{
        cin >> k >> l;
        if(k == 1){
          T += l;
        }
        else{
          S = S + l;
        }
      }
    }
    else{
      if(j == 1){
        d = true;
      }
      else{
        cin >> k >> l;
        if(k == 2){
          T += l;
        }
        else{
          S = S + l;
        }
      }
    }
  }
  if(d){
    reverse(T.begin(), T.end());
    AA(T+S);
    }
  else{
    reverse(S.begin(), S.end());
    AA(S+T);  
  }
  return 0;
}