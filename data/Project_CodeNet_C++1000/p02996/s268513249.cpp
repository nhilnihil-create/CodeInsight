#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  //input
  int n;
  cin >> n;
  vector<P> task(n);  //締め切り，作業時間
  REP(i,n){
    int a, b;
    cin >> a >> b;
    task[i] = make_pair(b,a);
  }
  //締切の早い順にsort
  sort(ALL(task));
  //タスクの合計が，締め切りを超えていたらだめ
  ll sum = 0;
  REP(i,n){
    sum += task[i].second;
    if(sum > task[i].first){
      cout << "No" << endl;
      return 0;
    }

  }

  //全てokなら出力する．
  cout << "Yes" << endl;
  return 0;
}