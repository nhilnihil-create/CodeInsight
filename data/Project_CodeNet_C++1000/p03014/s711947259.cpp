#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int H,W; cin>>H>>W;
  vector<string> S(H); rep(i,H)cin>>S.at(i);
  vector<vector<int>> L(H,vector<int> (W,-1));
  vector<vector<int>> R(H,vector<int> (W,-1));
  vector<vector<int>> B(H,vector<int> (W,-1));
  vector<vector<int>> U(H,vector<int> (W,-1));
  rep(i,H){
    rep(j,W){
      if(S.at(i).at(j)=='.'){
        if(j>0&&S.at(i).at(j-1)!='#')L.at(i).at(j)=L.at(i).at(j-1)+1;
        else L.at(i).at(j)=1;
      }
    }
    for(ll j = W-1; j>= 0; j--){
      if(S.at(i).at(j)=='.'){
        if(j<W-1&&S.at(i).at(j+1)!='#')R.at(i).at(j)=R.at(i).at(j+1)+1;
        else R.at(i).at(j)=1;
      }
    }
  }
  rep(i,W){//横へスライド
    rep(j,H){
      if(S.at(j).at(i)=='.'){
        if(j>0&&S.at(j-1).at(i)!='#')U.at(j).at(i)=U.at(j-1).at(i)+1;
        else U.at(j).at(i)=1;
      }
    }
    for(int j = H-1; j>= 0; j--){
      if(S.at(j).at(i)=='.'){
        if(j<H-1&&S.at(j+1).at(i)!='#')B.at(j).at(i)=B.at(j+1).at(i)+1;
        else B.at(j).at(i)=1;
      }
    }
  }
  ll res = 0;
  rep(i,H){
    rep(j,W){
      if(S.at(i).at(j)=='#')continue;
      ll tmp = L.at(i).at(j)+R.at(i).at(j)+U.at(i).at(j)+B.at(i).at(j)-3;
      res = max(res,tmp);
    }
  }
  cout<<res<<endl;
}