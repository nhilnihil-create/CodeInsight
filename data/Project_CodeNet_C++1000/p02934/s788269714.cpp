#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
   cin>>n;
  
  	double a[n];
  	rep(i,n)cin>>a[i];
  
  double ans;
  
  rep(j,n){
  	ans+=1/a[j];
  }
  
  cout<<1/ans<<endl;
  
}