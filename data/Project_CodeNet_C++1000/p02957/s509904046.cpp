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
  int a,b;cin>>a>>b;
  if((a+b)%2==0)cout<<(a+b)/2<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
  return 0;
}