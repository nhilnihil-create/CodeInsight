#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
ll b[100009];

int main() {
	int n;
  	cin>>n;
  
  	rep(i,n)cin>>b[i];
  
  	int ans=b[n-2]+b[0];
  
  	for(int j=0;j<n-1;j++){
    	ans += min(b[j-1],b[j]);
    }
  
  cout<<ans<<endl;


}