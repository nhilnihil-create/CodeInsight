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

signed main(){
  int n;
  long double a[110],ans;
  cin>>n;
  rep(i,n){
    cin>>a[i];
    ans+=1/a[i];
  }
  cout<<setprecision(15)<<1/ans<<endl;
  return 0;
}