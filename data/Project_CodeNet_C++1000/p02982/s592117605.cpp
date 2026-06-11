#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
#define P pair<int, int>
#define ll long long
const int MOD = 1000000007;
//bitset<64>(x).count()
//fixed << setprecision(15) << 

int main (){
  int d, n;
  cin >> n >> d;
  int x[n][d];
  rep(i, n){
    rep(j,d){
      cin >> x[i][j];
    }
  }
  int ans = 0;
  rep(i, n){
    for(int j=i+1;j<n;j++){
      int tmp = 0;
      rep(k, d)
        tmp += pow((double)(x[i][k]-x[j][k]),2);
      bool check = false;
      for(int k=1;k<=tmp;k++){
        if(pow((double)(k),2)==tmp)
          check = true;
      }
      if(check) ans++;
    }
  }
  cout << ans << endl;
  
}
