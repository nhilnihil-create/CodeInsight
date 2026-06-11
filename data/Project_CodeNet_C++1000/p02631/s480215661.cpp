#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;  
  cin>>n;
  int a[200005];
  rep(i,n) cin>>a[i];
  int keta=0;
  while(1){
    int cnt1=0;
    int end=0;
    rep(i,n){
      if(a[i]>=(1<<keta)) cnt1+=(a[i]>>keta)&1;
      if(a[i]<=(1<<(keta+1))-1) end++;
    }
    if(cnt1%2==1){
      rep(i,n){
	a[i]^=1<<keta;
      }
    }
    keta++;
    if(end==n) break;
    //printf("%d %d\n",cnt1,keta);
  }
  rep(i,n) cout<<a[i]<<' ';
  cout<<endl;
  return 0;
}
