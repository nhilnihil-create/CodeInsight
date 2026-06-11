#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int N;
vector<string> ans;

void BFS(int n){
  queue<string> q;
  q.push("a");
  while(!q.empty()){
    string s = q.front(); q.pop();
    if(s.size() == n){
      ans.push_back(s);
    }else{
      int cnt = 0;
      REP(i, s.size()){
        cnt = max(cnt, (s[i]-'a'));
      }
      for(int j = 0; j <= cnt+1; j++){
        string S = s + (char)('a' + j);
        q.push(S);
      }
    } 
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  BFS(N);
  for(auto i : ans){
    cout << i << endl;
  }
}