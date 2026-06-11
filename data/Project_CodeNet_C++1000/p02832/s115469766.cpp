#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)

int main(){
  int n;	cin >> n;
  vector<int>	a(n);
  rep(i,n)	cin >> a[i];
  
  int c=0;
  int max=0;
  bool ok=true;
  rep(i,n){
    if(a[i]==1)	ok=false;
    if(a[i]!=max+1)	continue;
    c++;
    max++;
  }
  if(ok){
    cout << -1;
    return 0;
  }
  cout << n-c;
}