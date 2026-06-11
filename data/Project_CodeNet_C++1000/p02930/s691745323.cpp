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

int hen[550][550];
int f(int a,int b){
  int res=1;
  while(1){
    if(a%2!=b%2)return res;
    a/=2,b/=2;
    res++;
  }
}
signed main(){
  int n;cin>>n;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      cout<<f(i,j)<<" ";
    }
    cout<<endl;
  }
  return 0;
}