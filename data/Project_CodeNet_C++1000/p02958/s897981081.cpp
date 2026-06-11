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
  int n;cin>>n;
  int cnt=0;
  rep(i,n){
    int x;cin>>x;
    if(x!=i+1)cnt++;
  }
  if(cnt<=2)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}