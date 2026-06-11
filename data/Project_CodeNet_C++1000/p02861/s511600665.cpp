#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[100010];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
//bitset<64>(x).count()
//fixed << setprecision(15) << 
int a[10][2] = {} ;
double dist(int x, int y){
  double ans;
  ans = pow(pow(a[x][0]-a[y][0],2)+pow(a[x][1]-a[y][1],2),0.5);
  return ans ;
}

int main (){
  int n;
  cin >> n;
  rep(i,n){
    cin >> a[i][0] >> a[i][1];
  }
  int O[n];
  rep(i,n)
    O[i] = i;
  double ans = 0;
  do{
    rep(i,n-1)
      ans += dist(O[i],O[i+1]);
  }while(next_permutation(O,O+n));
  int tmp = 1;
  for(int i=2;i<=n;i++)
    tmp *= i;
  cout << fixed << setprecision(15) << ans/tmp << endl;
}