#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------

int main(){
  int N,A,B,C,D;
  cin >> N >> A >> B >> C >> D;
  string S;
  cin >> S;
  S = '#' + S;
  if(C < D || C < B){
    for(int i=A; i<=C; i++){
      if(S[i] == '#' && S[i+1] == '#'){
        cout << "No" << endl;
        return 0;
      }
    }
    for(int i=B; i<=D; i++){
      if(S[i] == '#' && S[i+1] == '#'){
        cout << "No" << endl;
        return 0;
      }
    }
  }else{
    for(int i=A; i<=C; i++){
      if(S[i] == '#' && S[i+1] == '#'){
        cout << "No" << endl;
        return 0;
      }
    }
    bool can = false;
    for(int i=B; i<=D; i++){
      if(S[i-1]!='#' && S[i]!='#' && S[i+1]!='#'){
        can = true;
      }
    }
    if(!can){
      cout << "No" << endl;
      return 0;
    }
  }
  cout<< "Yes" << endl;
  return 0;
}
