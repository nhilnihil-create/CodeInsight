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
  ll n,k; cin >> n >> k;
  vi a(n);
  rep(i,n){
    cin >> a[i];
    --a[i];
  }
  map<int,int> mp;
  int now = 0;
  vi place;
  while(1){
    if(mp[now] == 2) break;
    mp[now]++;
    place.emplace_back(now);
    now = a[now];
  }
  vi once,twice;
  int one = 0, two = 0;
  for(auto x : mp){
    if(x.second == 1) one++;
    else two++;
  }
  rep(i,one) once.emplace_back(place[i]);
  rep(i,two) twice.emplace_back(place[i+one]);
  if(k < one){
    cout << once[k]+1;
  }else{
    k -= one;
    cout << twice[k%two]+1;
  }
  cout << endl;
  return 0;
}
