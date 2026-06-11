#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const int mod=1e9+7;

int main(){
  int n;
  cin>>n;
  ll ans=1;
  vector<int> res(3);
  rep(i,n){
    int a;
    cin>>a;
    int p=0;
    int q=-1;
    rep(j,3){
      if(res[j]==a){
        p++;
        q=j;
      }
    }
    if(p==0){
      cout<<0<<endl;
      return 0;
    }
    ans*=p;
    ans%=mod;
    res[q]++;
  }
  cout<<ans<<endl;
}