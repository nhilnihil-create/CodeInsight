#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)


int main(){
  int ans[1000000]={};
  int sum[1000]={0};

  rep(i,1,1000){
    sum[i] = sum[i-1]+i;
  }

  rep(i,0,999){
    rep(j,i+2,1001){
      ans[ sum[j]-sum[i] ]++;
    }
  }
  int n;
  while(cin >> n){
    if(n==0)break;
    cout << ans[n] << endl;
  }

}