#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

  int counter(int x){
  	if(x==0) return 0;
    return counter(x>>1)+(x&1);
  }

int main() {
	int n;
  	cin>>n;
  	
  	int a[20];
    int x[20][20];
  	int y[20][20];
  

  
  for(int i=1;i<=n;i++){
  	cin>>a[i];
    for(int j=1;j<=a[i];j++){
    	cin>>x[i][j]>>y[i][j];
    }
  }
  
  int ans=0;
  for(int bits = 1; bits<(1 << n);bits++){
  	bool ok = true;
    for(int i=1;i<=n;i++){
    	if(!(bits &(1 <<(i-1))))continue;
      for(int j=1;j<=a[i];j++){
      	if(((bits>>(x[i][j]-1))&1)^y[i][j])ok=false;
      }
    }
    if(ok)ans=max(ans,counter(bits));
  }
  cout<<ans<<endl;
  	
}