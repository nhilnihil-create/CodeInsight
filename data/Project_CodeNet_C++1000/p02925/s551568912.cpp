//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<vector<int> > a(n,vector<int>(n-1));
  rep(i,n)rep(j,n-1){
    cin >> a[i][j];
    a[i][j]--;
  }
  rep(i,n){
    reverse(all(a[i]));
  }
  set<i_i> st1;
  set<i_i> st2;
  int day=0;
  while(1){
    set<i_i> st1; // 初期化
    if(st2.empty()){
      rep(i,n){ //初回のみループ回す
        if(a[i].empty()) continue;
        if(a[a[i].back()].empty()) continue;
        if(a[a[i].back()].back()==i){
          int mn=min(i,a[i].back());
          int mx=max(i,a[i].back());
          st1.insert(i_i(mn,mx));
        }
      }
    }
    else{
      for(auto c:st2){
        int i=c.first;
        if(a[i].size()&&a[a[i].back()].size()&&a[a[i].back()].back()==i){
          int mn=min(i,a[i].back());
          int mx=max(i,a[i].back());
          st1.insert(i_i(mn,mx));
        }
        i=c.second;
        if(a[i].size()&&a[a[i].back()].size()&&a[a[i].back()].back()==i){
          int mn=min(i,a[i].back());
          int mx=max(i,a[i].back());
          st1.insert(i_i(mn,mx));
        }
      }
    }
    if(st1.empty()){
      bool f=1;
      rep(i,n){
        if(a[i].size()) f=0;
      }
      if(f) break;
      else{
        cout << -1 << endl;
        return 0;
      }
    }
    st2=st1; //次の周期ではst1は空である必要があるので2にコピー
    for(auto c:st1){
      a[c.first].pop_back();
      a[c.second].pop_back();
    }
    day++;
  }
  cout << day << endl;
}