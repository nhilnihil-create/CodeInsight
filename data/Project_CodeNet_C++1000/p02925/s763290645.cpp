#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin>>N;
  vector<vector<int>>A(N,vector<int>(N-1));
  for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
      cin>>A[i][j];
      A[i][j]--;
    }
    reverse(A[i].begin(),A[i].end());
  }
  set<pair<int,int>>k;
  queue<pair<int,int>>now;
  auto check=[&](int a){
    if(A[a].size()==0){return;}
    int b=A[a].back();
    if(A[b].back()==a){
      if(a>b){swap(a,b);}//cout<<1<<endl;
      if(!k.count(make_pair(a,b))){now.push(make_pair(a,b));k.insert(make_pair(a,b));}
    }
  };
  for(int i=0;i<N;i++){
    check(i);
  }

  int day=0;
  while(!now.empty()){
    day++;//cout<<day<<endl;
    queue<pair<int,int>>BACK;
    swap(BACK,now);
    while(!BACK.empty()){
      auto p=BACK.front();BACK.pop();
      int a=p.first,b=p.second;
      A[a].pop_back();
      A[b].pop_back();
      check(a);
      check(b);
    }
  }
  for(int i=0;i<N;i++){
    if(A[i].size()!=0){
      cout<<-1<<endl;return 0;
    }
  }
  cout<<day<<endl;
  return 0;  
}