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
const int INF=100100100100100;

const int po=1000000000;
signed main(){
  int n,k,s;cin>>n>>k>>s;
  rep(i,n){
    if(i<k)cout<<s<<" ";
    else{
      if(s<po)cout<<s+1<<" ";
      else cout<<1<<" ";
    }
  }
  cout<<endl;
  return 0;
}