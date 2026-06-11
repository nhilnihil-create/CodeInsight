#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans = 0;
  for(int i=1;i<=n;i++){
  	if(n%i==0){
  		ans += (n/i)-1;
	}
	else{
		ans += n/i;
	}
  }
  cout<<ans<<endl;
}