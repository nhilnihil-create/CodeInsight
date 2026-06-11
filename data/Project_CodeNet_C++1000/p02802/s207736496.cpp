#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int wa[100010];
bool ac[100010];
signed main(){
  int n,m;cin>>n>>m;
  rep(i,m){
    int x;cin>>x;x--;
    string s;cin>>s;
    if(!ac[x]){
      if(s=="WA")wa[x]++;
      else ac[x]=true;
    }
  }
    int WA=0,AC=0;
    rep(i,n){
      if(ac[i])AC++,WA+=wa[i];
    }
    cout<<AC<<" "<<WA<<endl;
  
  return 0;
}
