#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int a[n];
  rep(i,n)cin >> a[i];

  sort(a,a+n,greater<int>());

  int sum=0;
  rep(i,n)sum+=a[i];
  
  string ans="No";
  int cnt=0;
  rep(i,m){
    if(4*m*a[i]>=sum)cnt++;
    else break;
  }
  if(m<=cnt)ans="Yes";
  cout << ans << endl;
}