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
  int p[n], q[n];
  rep(i,n){
    cin >> p[i];
    p[i]--;
  }
  rep(i,n){
    cin >> q[i];
    q[i]--;
  }
  int o[n], ans = 0;
  rep(i,n){
    o[i] = i;
  }
  int j = 0;
  do{
    bool flag = true;
    rep(i,n){
      if(p[i]!=o[i])
        flag = false;
    }
    if(flag){
      ans += j;
      break;
    }
    j++;
  }while(next_permutation(o,o+n));
  j = 0;
  rep(i,n){
    o[i] = i;
  }
  do{
    bool flag = true;
    rep(i,n){
      if(q[i]!=o[i])
        flag = false;
    }
    if(flag){
      ans -= j;
      break;
    }
    j++;
  }while(next_permutation(o,o+n));
  cout << abs(ans) << endl;
}