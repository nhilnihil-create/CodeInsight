#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll tmp1,tmp2;
const ll mod = 1e9+7;
const int INF = 1e9;
const ll INFLONG = 1e18;
ll n;
ll a[500][500];
int main(){
  cin >> n;
  ll cou;
  ll tmp3,tmp4;
  rep(i,n){
    REP(j,i+1,n){
      cou = 1;
      while(1){
        tmp1 = i / (ll)pow(2,cou);
        tmp2 = j / (ll)pow(2,cou);
        if(tmp1 == tmp2){
          a[i][j] = cou;
          break;
        }else{
          cou++;
        }
      }
    }
  }
  rep(i,n){
    REP(j,i+1,n){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
