#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main() 
{
  ll N,X,Y; cin>>N>>X>>Y; X--; Y--;
  vector<vector<ll>> graph(N,vector<ll>(0));
  rep(i,N-1)
  {
    graph.at(i).push_back(i+1);
    graph.at(i+1).push_back(i);
  }
  graph.at(X).push_back(Y);
  graph.at(Y).push_back(X);
  
  vector<ll> ans_list(N,0);
  rep(i,N)
  {
    vector<bool> checked(N,false);
    vector<ll> min_path(N,INF);
    queue<ll> que;
    que.push(i);
    min_path.at(i)=0;
    checked.at(i)=true;
    while(!que.empty())
    {
      auto n=que.front();
      que.pop();
      //if(checed.at(n)) continue;
      //checked.at(n)=true;
      auto vec=graph.at(n);
      for(auto node:vec)
      {
        //if(node<=i) continue;
        if(checked.at(node)) continue;
        chmin(min_path.at(node),min_path.at(n)+1);
        que.push(node);
        checked.at(node)=true;
        ans_list.at(min_path.at(node))++;
      }  
    }
    /*
    rep(i,N)
    {
      if(i!=0) cout<<" ";
      cout<<min_path.at(i);
    }
    cout<<endl;
    */
  }
  
  for(int i=1;i<N;i++)
  {
    cout<<ans_list.at(i)/2<<endl;
  }  
  return 0;
}
