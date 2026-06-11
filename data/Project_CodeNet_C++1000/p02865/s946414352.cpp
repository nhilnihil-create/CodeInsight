#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin>>n;
  	int ans = n/2;
  	if(n%2 == 0)ans-=1;
  	cout<<ans<<"\n";
	return 0;
}