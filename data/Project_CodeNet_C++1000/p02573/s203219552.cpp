#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  int A, B;
  vector<vector<int> > friends(N);
  for(int i=0;i<M;++i) {
    cin>>A>>B;
    A--;
    B--;
    friends[A].push_back(B);
    friends[B].push_back(A);
  }
  int groups[N];
  for(int i=0;i<N;++i) groups[i] = -1;
  int group = 0;
  queue<int> que;
  int state;
  for(int i=0;i<N;++i) {
    if(groups[i]>-1) continue;
    que.push(i);
    while(!que.empty()) {
      state = que.front();que.pop();
      if(groups[state]>-1) continue;
      groups[state] = group;
      for(int j=0;j<friends[state].size();++j) {
        if(groups[friends[state][j]]>-1) continue;
        que.push(friends[state][j]);
      }
    }
    group++;
  }
  int num[group];
  for(int i=0;i<group;++i) num[i] = 0;
  for(int i=0;i<N;++i) {
    num[groups[i]]++;
  }
  int ans = 0;
  for(int i=0;i<group;++i) ans = max(ans, num[i]);
  cout<<ans<<endl;
}

