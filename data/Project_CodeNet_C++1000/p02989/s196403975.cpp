#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  cin>>n;
  	int d[n];
  
  
  rep(i,n)cin>>d[i];
  
  sort (d,d+n);
  
  int p=n/2;
  int q=n/2-1;
  int ans=0;
  
  if(d[q]==d[p])cout<<0<<endl;
  
  else{
  for(int i=d[q];i<d[p];i++){
	ans++;
  }
  
  cout<<ans<<endl;
  }
  }
