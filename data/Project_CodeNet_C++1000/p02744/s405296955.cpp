#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1<<30;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<set<int> > pls;
map<string,int> ma,num;
int n;
void dfs(string s, char mx){
  if(s.size()==n){
    cout << s << endl;
    return;
  }
  for(char c='a' ; c<=mx+1 ; c++){
    dfs(s+c, max(c, mx));
  }
}
int main(){
  cin >> n;
  dfs("", 'a'-1);
  return 0;
}
