#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
typedef long double ld;
using ll=long long;
using namespace std;
const int mod=1e9+7;
const ll inf = 1LL << 60;
const ld pi = (acos(-1));
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

float dis(vector<int> a,vector<int> b){
   float distance=0;
   for(int i=0;i<a.size();i++){
     distance+=(a[i]-b[i])*(a[i]-b[i]);
   }
   return distance;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  
  int n,d; cin >> n >> d;
  vector<vector<int>> x(n,vector<int>(d));
  int ans=0;
  set<int> s;
  rep(i,1,100001) s.emplace(i*i);
  rep(i,0,n)rep(j,0,d) cin >> x[i][j];
  rep(i,0,n)rep(j,i+1,n){
    int d = dis(x[i],x[j]);
    if(s.count(d)) ans++;
  }
  cout << ans << endl;
}