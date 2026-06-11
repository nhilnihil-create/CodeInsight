#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string s;
  cin >> s;
  deque<char> que;
  for(auto t : s) que.push_back(t);
  int q;
  cin >> q;
  int cnt = 0;
  rep(i,q){
    int a;
    cin >> a;
    if(a == 1) cnt++;
    else{
      int f;
      cin >> f;
      char c;
      cin >> c;
      if(f == 1){
        if(cnt%2 == 0) que.push_front(c);
        else que.push_back(c);
      }
      else{
        if(cnt%2 == 0) que.push_back(c);
        else que.push_front(c);
      }
    }
  }
  if(cnt%2 == 1) reverse(que.begin(),que.end());
  for(auto t : que) cout << t;
}
