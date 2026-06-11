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
  ll ans = 0;
  for(int i=1;i< 1000001;i++){
    for(int j=1;j< 1000001;j++){
      if(n-i*j>0){
        ans++;
      } else{
        break;
      }
    }
  }
  cout << ans << endl;
}
