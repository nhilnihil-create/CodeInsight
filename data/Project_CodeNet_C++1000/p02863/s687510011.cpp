#include <bits/stdc++.h>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,T;
  cin >> N >> T;
  vector<pair<int,int>> AB(N);
  for(int i=0;i<N;i++)  cin >> AB.at(i).fi >> AB.at(i).se;

  sort(all(AB));
  vector<vector<int>> dp(N+1,vector<int>(T+1,0));
  for(int i=0;i<N;i++){
    for(int j=0;j<T+1;j++){
      chmax(dp.at(i+1).at(j),dp.at(i).at(j));
      if(j>=T)  continue;
      int tmp=min(T,j+AB.at(i).fi);
      chmax(dp.at(i+1).at(tmp),dp.at(i).at(j)+AB.at(i).se);
    }
  }
  cout << dp.at(N).at(T) << endl;

  return 0;
}