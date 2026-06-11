#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  string s; cin >> s;
  list<string> l;
  l.push_back(s);
  int q; cin >> q;
  int front = 1;
  rep(i,q){
    int t; cin >> t;
    if(t == 1) front *= -1;
    else{
      int f; cin >> f;
      string c; cin >> c;
      if(front == 1){
        if(f == 1) l.push_front(c);
        else l.push_back(c);
      }else{
        if(f == 2) l.push_front(c);
        else l.push_back(c);
      }
    }
  }
  if(front == 1) for(auto x : l) cout << x;
  else{
    reverse(all(l));
    for(string x : l){
      reverse(all(x));
      cout << x;
    }
  }
  cout << "\n";
  return 0;
}
