#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x,t,dot;
	cin>>n>>x>>t;
	dot=n/x;
	if (n%x>0){
		dot++;
	}
	cout<<dot*t;
	return 0;
}