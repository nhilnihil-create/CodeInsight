#include<bits/stdc++.h>
using namespace std;
long long n,ans,x=100;
int main(){
	cin>>n;
	while (n!=0){
		x=x+x/100;
		ans++;
		if (x>=n) break;
	}
	cout<<ans<<endl;
	return 0;
}