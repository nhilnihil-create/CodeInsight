#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()

int main(){
  int N;cin>>N;
  vector<pii> task;
  for(int i=0; i<N; i++){
    int a,b;cin>>a>>b;
    task.push_back({b,a});//締め切り, 必要時間
  }
  sort(all(task));

  ll used = 0;

  for(auto x: task){
    //cout<<x.first<<","<<x.second<<endl;
    used += x.second;
    if(used > x.first){
      cout<<"No\n";
      return 0;
    }
  }
  cout<<"Yes\n";
  return 0;
}