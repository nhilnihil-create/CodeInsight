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
  int a[2];
  cin>>a[0]>>a[1];
  sort(a,a+2);
  rep(i,a[1])cout<<a[0];
  cout<<endl;
  return 0;
}