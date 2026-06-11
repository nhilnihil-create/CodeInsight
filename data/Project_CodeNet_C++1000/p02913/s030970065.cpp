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
  int N;
  string S;
  cin >> N >> S;

  int ans=0;
  for(int i=1;i<N;i++){
    int ma=0;
    int now=0;
    for(int j=0;j<N;j++){
      if(j+i>=N)  break;
      if(S.at(j)!=S.at(j+i))  now=0;
      else  now++;
      chmax(ma,now);
    }
    chmin(ma,i);
    chmax(ans,ma);
  }
  cout << ans << endl;

  return 0;
}