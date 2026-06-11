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
  int K;
  cin>>K;
  queue<string> que;
  que.push("1");
  que.push("2");
  que.push("3");
  que.push("4");
  que.push("5");
  que.push("6");
  que.push("7");
  que.push("8");
  que.push("9");
  string state;
  string ans;
  for(int i=1;i<=K;++i) {
    state = que.front();que.pop();
    if(i==K) ans = state;
    if(state[state.size()-1]=='0') {
      state.push_back('0');
      que.push(state);
      state.pop_back();
      state.push_back('1');
      que.push(state);
      state.pop_back();
    }
    else if(state[state.size()-1]=='9') {
      state.push_back('8');
      que.push(state);
      state.pop_back();
      state.push_back('9');
      que.push(state);
      state.pop_back();
    }
    else {
      state.push_back(state[state.size()-1]-1);
      que.push(state);
      state.pop_back();
      state.push_back(state[state.size()-1]);
      que.push(state);
      state.pop_back();
      state.push_back(state[state.size()-1]+1);
      que.push(state);
      state.pop_back();
    }
  }
  cout<<ans<<endl;
}

