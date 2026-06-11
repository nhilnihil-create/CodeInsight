#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
int ans=0;
  int n, m ,q;

void dfs(vector<int> A){
  if(A.size()==n+1){
    int score=0;
    rep(i, q){
      if(A[b[i]]-A[a[i]]==c[i]){
        score+=d[i];
      }
    }
    ans=max(ans, score);
    return;
  }
  A.push_back(A.back());
  while(A.back()<=m){
    dfs(A);
    A.back()++;
  }
}

int main(){
  cin >> n >> m >> q;
  a.resize(q);b.resize(q);c.resize(q);d.resize(q);
  rep(i, q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  dfs(vector<int> (1, 1));
  cout << ans << endl;
  return 0;
}
