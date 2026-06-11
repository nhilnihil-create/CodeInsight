#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<set<int>> num(n);
  rep(i,m){
    int s,c; cin >> s >> c;
    num[--s].insert(c);
  }
  rep(i,n){
    if(num[i].empty()){
      if(n == 1) num[i].insert(0);
      else{
        if(!i) num[i].insert(1);
        else num[i].insert(0);
      }
    }else if(2 <= num[i].size()){
      cout << -1;
      return 0;
    }
  }
  if(n == 1){
    cout << *num[0].begin();
    return 0;
  }else if(n == 2){
    for(int i = 10; i < 100; i++){
      bool ok = true;
      if(*num[0].begin() != i/10) ok = false;
      if(*num[1].begin() != i%10) ok = false;
      if(ok){
        cout << i;
        return 0;
      }
    }
  }else if(n == 3){
    for(int i = 100; i < 1000; i++){
      bool ok = true;
      if(*num[0].begin() != i/100) ok = false;
      if(*num[1].begin() != i/10%10) ok = false;
      if(*num[2].begin() != i%10) ok = false;
      if(ok){
        cout << i;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
