#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define itn long long
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rrep(i,n) for(int i=(int)(n);i>=0;--i)
#define debug(x) cout << #x << "=" << (x) << endl;
const ll MOD=1e9+7;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> void fail(T v){cout << v << endl;exit(0);}
//template end

void solve(){
  int N;
  cin>>N;
  map<string,int> m;
  rep(i,N){
    string s;
    cin>>s;
    m[s]=1;
  }
  int M;
  cin>>M;
  int st=1;
  string r[]={"Unknown ","Opened by ","Closed by "};
  rep(i,M){
    string s;
    cin>>s;
    if(m[s]){cout<<r[st]<<s<<endl;st^=3;}
    else cout<<r[0]<<s<<endl;
  }
}
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
