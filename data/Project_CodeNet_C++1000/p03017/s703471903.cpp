#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 100000000000000009
#define int long long
using P = pair<int,int>;
signed main(){
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  a--;b--;c--;d--;
  string s;
  cin >> s;
  vint block(n);
  int count = 0;
  rep1(i,n){
    if(s[i-1] == '#' && s[i] == '#') count++;
    block[i] = count;
  }
  vint road(n);
  count = 0;
  for(int i = 1;i<n-1;i++){
    if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') count++;
    road[i] = count;
  }
  bool flag = true;
  if(block[c]-block[a] > 0) flag = false;
  if(block[d]-block[b] > 0) flag = false;
  if(d < c) if(road[d] - road[b-1] == 0) flag = false;
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
} 