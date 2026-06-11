#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<ll>a(n); 
  rep(i,n)cin>>a[i];
  ll sum=0;
  rep(i,n)sum+=a[i];
  ll tmp=0;
  vector<ll>ans(n);
  for(int i=1;i<n;i+=2){
    tmp+=a[i];
  }
  ans[0]=sum-2*tmp;
  for(int i=1;i<n;i++){
    ans[i] = 2*a[i-1]-ans[i-1];
  }
  rep(i,n)cout<<ans[i]<<endl;
}