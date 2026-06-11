#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  string s = "";
  queue<string> que;
  que.push(s);
  while(que.front().size()<N){
    string S=que.front();
    int x = que.front().size();
    set<char> st;
    REP(i,S.size()){
      st.insert(S.at(i));
    }
    int y = st.size();
    que.pop();
    REP(j,x+1){
      if(j<=y){
        que.push(S+char('a'+j));
      }
    }
  }
  
  while(!que.empty()){
    cout << que.front() << endl;
    que.pop();
  }
}