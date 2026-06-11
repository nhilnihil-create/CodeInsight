#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;
      

int main(){
  int n,m;
  cin>>n>>m;
  int cnt=0;
  int l,r;
  l=1; r=n/2-n/2%2;
  int memo=r;
  while(l<r){
    if(cnt>=m) break;
    cout<<l<<' '<<r<<endl;
    cnt++;
    l++; r--;
  }
  l=memo+1; r=n;
  if((r-l+1)%2==0) r--;
  while(l<r){
    if(cnt>=m) break;
    cout<<l<<' '<<r<<endl;
    cnt++;
    l++; r--;
  }
  return 0;
}
