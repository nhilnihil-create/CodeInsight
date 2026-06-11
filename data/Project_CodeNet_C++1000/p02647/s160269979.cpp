#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n,k; cin>>n>>k;
  vector<int>a(n+1);
  rep(i, n)cin>>a[i];

  rep(i, k){
    vector<int>na(n+1);
    rep(ci, n){
      int l = ci-a[ci];
      if(l < 0)l=0;
      na[l]++;

      int r = ci+a[ci]+1;
      if(r > n)r = n;
      na[r]--;

//cout<<i<<' '<<r<<endl;
//rep(i, n+1)cout<<na[i]<<' ';cout<<endl;

    }
    rep(i, n)na[i+1]+=na[i];
    bool f=true;
    rep(i, n)if(a[i]!=na[i])f=false;
    if(f)break;

    swap(na, a);
//    rep(i, n+1)cout<<a[i]<<' ';cout<<endl;

  }
  rep(i, n)cout<<a[i]<<' ';cout<<endl;

  return 0;
}