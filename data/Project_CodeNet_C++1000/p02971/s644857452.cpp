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


const int MOD=1000000007;
int INF=100100100100100;
int a[200010];
int b[200010];
signed main(){
  int n;cin>>n;
  rep(i,n){
    cin>>a[i];
    b[i]=a[i];
  }
  sort(b,b+n);
  rep(i,n){
    if(a[i]!=b[n-1])cout<<b[n-1]<<endl;
    else{
      if(b[n-2]==b[n-1])cout<<b[n-1]<<endl;
      else cout<<b[n-2]<<endl;
    }
  }
  return 0;
}
