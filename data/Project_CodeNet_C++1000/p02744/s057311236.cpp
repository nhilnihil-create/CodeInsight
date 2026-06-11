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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  queue<string> que;
  string state = "a";
  que.push(state);
  char maxchr;
  while(!que.empty()) {
    state = que.front();que.pop();
    if(state.size()==N) {
      cout<<state<<endl;
      continue;
    }
    maxchr = state[0];
    for(int i=0;i<state.size();++i) maxchr = max(maxchr, state[i]);
    for(char a='a'; a<=maxchr+1;++a) {
      state.push_back(a);
      que.push(state);
      state.pop_back();
    }
  }
}

