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
  int N,M;
  string S;
  cin >> N >> M >> S;

  vector<int> dp(N+1,1e9);
  dp.at(0)=0;
  int r=0;
  int nr=-1;
  for(int i=1;i<N+1;i++){
    if(r+M<i){
      if(nr==-1){
        cout << -1 << endl;
        return 0;
      }
      r=nr;
      nr=-1;
    }
    if(S.at(i)=='1')  continue;
    dp.at(i)=dp.at(r)+1;
    nr=i;
  }
  vector<int> ans;
  int now=N;
  int nnow=-1;
  for(int i=N;i>=0;i--){
    if(now-M>i){
      ans.p_b(now-nnow);
      now=nnow;
      nnow=-1;
    }
    if(S.at(i)=='1')  continue;
    nnow=i;
  }
  if(nnow!=-1)  ans.p_b(now-nnow);
  reverse(all(ans));
  for(int i=0;i<sz(ans);i++)  cout << ans.at(i) << " ";
  cout << endl;

  return 0;
}