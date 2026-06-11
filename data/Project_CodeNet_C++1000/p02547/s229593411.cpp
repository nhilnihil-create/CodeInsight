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

int main(){
  int n;
  cin >> n;
  int a[n][2];
  rep(i,n){
    cin >> a[i][0] >> a[i][1];
  }
  bool flag = false;
  rep(i, n-2)
    if(a[i][0]==a[i][1]&&a[i+1][0]==a[i+1][1]&&a[i+2][0]==a[i+2][1])
      flag = true;
  if(flag)
    cout << "Yes" << endl;
  else 
    cout << "No" << endl;
}
