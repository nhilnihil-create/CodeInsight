#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;



int main(){
  int N; cin>>N;
  vector<queue<int>> G(1010);
  rep(i,N){
    rep(j,N-1){
      int a;
      scanf("%d",&a);
      G.at(i+1).emplace(a);
    }
  }
  int MAXday = N*(N-1)/2;
  int game = N*(N-1)/2;
  set<int> player;
  set<int> today;//前日試合をした人
  
  for(int d = 1; d <= MAXday; d++){
    vector<bool> seen(1010,false);
    set<int> tommorow;
    int flag = 0;
    //初日
    if(d==1){
      rep1(i,N){
        if(seen.at(i))continue;
        else{
          int opponent = G.at(i).front();
          if(!seen.at(opponent)&&G.at(opponent).front()==i){
            seen.at(i)=true;
            G.at(i).pop();
            G.at(opponent).pop();
            if(!G.at(i).empty())tommorow.insert(i);
            if(!G.at(opponent).empty())tommorow.insert(opponent);
            seen.at(opponent)=true;
            game--;
            flag = 1;
            //cout<<"day "<<d<<" "<<i<<" vs "<<opponent<<endl;
          }
        }
      }
    }else{
      for(auto i:today){
        if(seen.at(i))continue;
        else{
          int opponent = G.at(i).front();
          if(!seen.at(opponent)&&G.at(opponent).front()==i){
            seen.at(i)=true;
            G.at(i).pop();
            G.at(opponent).pop();
            if(!G.at(i).empty())tommorow.insert(i);
            if(!G.at(opponent).empty())tommorow.insert(opponent);
            seen.at(opponent)=true;
            game--;
            flag = 1;
            //cout<<"day "<<d<<" "<<i<<" vs "<<opponent<<endl;
          }
        }
      }  
    }
    today = tommorow;//更新
    if(flag==0)break;
    if(game==0){
      cout<<d<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
