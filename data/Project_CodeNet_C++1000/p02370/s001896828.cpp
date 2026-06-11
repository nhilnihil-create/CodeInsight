#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using VL=vector<ll>;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
const long long INF =  999999999;

template <typename T>
vector<T> topologicalsort(vector<vector<T>> g,T v){
  T h[v];
  fill(h,h+v,0);
  //頂点は0~N-１と番号付けられていることに注意
  REP(i,g.size()){
    REP(j,g[i].size()){
      h[g[i][j]]++;
    }
  }
  
  stack <T> st;
  REP(i,v)if(h[i]==0)st.push(i);

  vector<T> ans;
  while(st.size()){
    T s=st.top();st.pop();
    ans.push_back(s);
    REP(i,g[s].size()){
      h[g[s][i]]--;
      if(h[g[s][i]]==0)st.push(g[s][i]);
    }
  }
  return ans;
}


int main(){
  ll N,M;
  cin>>N>>M;
  vector<vector<ll>> g(N);
  ll s,t;
  REP(i,M){
    scanf("%lld %lld",&s,&t);
    g[s].push_back(t);
  }
  vector <ll> ans;
  ans=topologicalsort(g,N);
  REP(i,ans.size()){
    cout << ans[i]<<endl;
  }
}
