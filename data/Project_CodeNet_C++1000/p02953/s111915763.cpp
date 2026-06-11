#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;
int n;
int a[100010];
signed main(){
  cin>>n;
  rep(i,n)cin>>a[i];
  string ans="Yes";
  a[0]--;
  rep(i,n-1){
    if(a[i+1]<a[i]){
      ans="No";break;
    }
    if(a[i+1]>a[i])a[i+1]--;
  }
  cout<<ans<<endl;
  return 0;
}