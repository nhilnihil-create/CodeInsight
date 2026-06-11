#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
  int n;
  cin>>n;
  
  int d[60];
  rep(i,n){
    cin>>d[i];
  }
  
  ll umee;

  
  rep(j,n){
    for(int k=j+1;k<n;k++)
    umee+=d[j]*d[k];
  }
  
  cout<<umee<<endl;
	
}