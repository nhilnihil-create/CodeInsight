#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n;cin>>n;
  queue<int> schedules[1000];
  rep(i, n)rep(j, n-1){
    int t;cin>>t; t--;
    schedules[i].push(t);
  }

  int days=0;
  while(true){
    set<int> s;
    rep(i, n){
      if(schedules[i].empty())continue;

      int opp = schedules[i].front();
      if(schedules[opp].front() == i)s.insert(i);
    }
    if(s.empty())break;
    days++;
    for(auto t:s) schedules[t].pop();
  }

  bool f=true;
  rep(i, n)if(schedules[i].size())f=false;

  if(f) cout<<days<<endl;
  else cout<<-1<<endl;

  return 0;
}