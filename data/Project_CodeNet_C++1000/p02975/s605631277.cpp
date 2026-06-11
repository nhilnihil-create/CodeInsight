#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
int INF = 1e9+7;
// const long long INF = 1LL<<60;


int main(){
  int N;
  cin >> N;
  map<int, int> mp;
  rep(i, N){
    int a;
    cin >> a;
    mp[a]++;
  }

  vector<P> vect;
  for(P p: mp){
    vect.push_back(p);
  }
  sort(vect.begin(), vect.end());

  bool ok = false;

  // Length = 1
  if(sz(vect)==1) if(vect[0].first == 0) ok = true;
  // Length = 2
  if(sz(vect)==2){
    int cnt_0 = vect[0].second;
    int cnt_1 = vect[1].second;
    if(2*cnt_0==cnt_1 && vect[0].first==0) ok = true;
    if(cnt_0==2*cnt_1 && vect[1].first==0) ok = true;
  }
  // Length = 3
  if(sz(vect)==3){
    if(vect[0].second*3==N && vect[1].second*3==N && vect[2].second*3==N){
      int x = vect[0].first;
      int y = vect[1].first;
      int z = vect[2].first;
      if(x == (y^z) && y==(x^z) && z==(x^y)) ok = true;
    }
  }
  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}
