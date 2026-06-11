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
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi a(n);
  int minus = 0, plus = 0;
  rep(i,n){
    cin >> a[i];
    if(0 < a[i]) plus++;
    if(a[i] < 0) minus++;
  }
  sort(all(a));
  int cnt = 0;
  vi x,y;
  while(1 < minus && a.size() != 1){
    cnt++;
    if(a.back() < 0) minus--;
    x.push_back(a.back());
    y.push_back(a[0]);
    a.back() -= a[0];
    minus--;
    a.erase(a.begin());
  }
  if(a.size() == 1){
    cout << a[0] << endl;
    rep(i,cnt) cout << x[i] << " " << y[i] << endl;
    return 0;
  }

  if(minus == 0 && a.size() == 2){
    cout << a[1]-a[0] << endl;
    cout << a[1] << " " << a[0];
    return 0;
  }
  int num = a[0];
  a.erase(a.begin());
  if(minus == 0){
    cnt++;
    x.push_back(num);
    y.push_back(a[0]);
    num -= a[0];
    a.erase(a.begin());
  }
  while(a.size() != 1){
    cnt++;
    x.push_back(num);
    y.push_back(a[0]);
    num -= a[0];
    a.erase(a.begin());
  }
  cnt++;
  x.push_back(a[0]);
  y.push_back(num);
  a[0] -= num;
  cout << a[0] << endl;
  rep(i,cnt) cout << x[i] << " " << y[i] << endl;
  // cout << "\n";
  return 0;
}
