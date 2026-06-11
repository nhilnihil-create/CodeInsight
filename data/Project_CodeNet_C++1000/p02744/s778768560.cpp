#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define each(a,x) for(auto a : (x))
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) ((a) = min((a),(b)))
#define chmax(a,b) ((a) = max((a),(b)))
#define in_range(x,l,r) ((l)<=(x) && (x)<(r))
#define printvec(a) rep(i,a) cout << a[i] << " \n"[i+1==(a).size()];
#define fs first
#define sc second
#define em emplace
#define eb emplace_back
#define sz size()
#define MP make_pair
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;

const ll INF = 1e8;
const D EPS = 1e-8;
const ll MOD = 1e9+7;

vector<string> rec(int n) {
  if (n == 1) {
    return vector<string>({"a"});
  }

  vector<string> res;
  vector<string> sub = rec(n-1);
  for (string s : sub) {
    char max_c = 'a';
    for (char c : s) {
      max_c = max(max_c, c);
    }
    max_c++;
    for (char c = 'a'; c <= max_c; c++) {
      res.push_back(s + c);
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n;
  
  vector<string> ans = rec(n);
  sort(all(ans));
  for (string s : ans) {
    cout << s << endl;
  }
}
