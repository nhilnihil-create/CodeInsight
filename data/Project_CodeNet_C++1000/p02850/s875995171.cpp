//g++ -std=gnu++14 a.cpp

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;
ll MODP = 998244353;

int main(){
  int N;
  cin >> N;
  vector<int> a(N-1),b(N-1);
  rep(i,N-1){
    cin >> a[i] >> b[i];
  }
  vector<vector<int>> edge(N+10);
  rep(i,N-1){
    edge[a[i]].push_back(b[i]);
    edge[b[i]].push_back(a[i]);
  }
  int ans = 0 , ans_dir = 0;
  rep(i,N+10){
    if(edge[i].size() > ans){
      ans = edge[i].size();
      ans_dir = i;
    }
  }
/*
  vector<int> num(N+10);
  vector<set<int>> eda(N+10);
  rep(i,N){
    num[a[i]]++;
    num[b[i]]++;
  }
  int ans = -1;
  int ans_dir = 0;
  rep(i,N+10){
    if(num[i] > ans){
      ans = num[i];
      ans_dir = i;
    }
  }
  */
  cout << ans << endl;
  vector<int> eda_ans(N+1,0);
  vector<set<int>> eda_set(N+1);
  rep(i,N+1){
    eda_set[i].insert(0);
  }
  /*
  for(int i = 1;i <= N;i++){
    for(int j = 1;j <= ans;j++){
      eda_set[i].insert(j);
    }
  }
  */

  queue<int> q;
  q.push(ans_dir);
  //cout << "始めます" << endl;
  map<pair<int,int>,int> ed;
  rep(i,N-1){
    ed[make_pair(a[i],b[i])] = 0;
  }
  while(!q.empty()){
    int a = q.front();
    int cur = 1;
    for(int i : edge[a]){
      int b = a , c = i;
      if(a > i){
        swap(b,c);
      }
      if(ed[make_pair(b,c)] != 0){
        continue;
      }else{
        //int t = *begin(eda_set[a]);
        while(ed[make_pair(b,c)] == 0){
          if(!eda_set[a].count(cur)){
            ed[make_pair(b,c)] = cur;
            eda_set[a].insert(cur);
            eda_set[i].insert(cur);
            cur++;
            //break;
          }else{
            cur++;
          }
        }
        //cout << "t : a = " << t << " " << a << endl;
        //ed[make_pair(b,c)] = t;
        q.push(i);
      }
    }
    q.pop();
  }
  rep(i,N-1){
    cout << ed[make_pair(a[i],b[i])] << endl;
  }

/*
      if(ed[make_pair()] == 0){
        eda_ans[i] = *begin(eda_set[a]);
        eda_set[a].erase(eda_ans[i]);
        q.push(i);
      }else{
        eda_set[a].erase(eda_ans[i]);
      }
    }
    q.pop();
  }

  for(int i = 1;i <= N-1;i++){
    cout << eda_ans[i] << endl;
  }
*/

/*




  vector<int> eda_num(N-1,0);
  vector<set<int>> eda_count(N+10);
  rep(i,N+10){
    for(int j = 1;j <= ans;j++)
      eda_count[i].insert(j);
  }
  rep(i,N-1){
    int t;
    if(*begin(eda_count[a[i]]) >= *begin(eda_count[b[i]])){
      t = *begin(eda_count[a[i]]);
    }else{
      t = *begin(eda_count[b[i]]);
    }
    for(int j = t;j <= ans;j++){
      if(eda_count[a[i]].count(t) && eda_count[b[i]].count(t)){
        eda_num[i] = t;
        eda_count[a[i]].erase(t);
        eda_count[b[i]].erase(t);
        break;
      }
    }

    for(int j = 1;j <= ans;j++){
      if(!eda_count[a[i]].count(j) && !eda_count[b[i]].count(j)){
        eda_num[i] = j;
        eda_count[a[i]].insert(j);
        eda_count[b[i]].insert(j);
        break;
      }
    }

  }
  rep(i,N-1){
    cout << eda_num[i] << endl;
  }
  */
  return 0;
}
