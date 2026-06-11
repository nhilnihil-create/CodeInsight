#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n,x;
  	cin>>n>>x;
  	
  	int l[n+1];
  rep(i,n+1)cin>>l[i];
  int hazumu=1;
  int sum=0;
  for(int i=0;i<n;i++){
  	sum+=l[i];
    if(sum<=x){
    	hazumu++;
    }
  }
	  
  cout<<hazumu<<endl;
}