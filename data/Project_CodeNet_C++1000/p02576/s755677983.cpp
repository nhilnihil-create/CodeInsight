#include <bits/stdc++.h>
using namespace std;
int N,X,T;
int main() {
	cin>>N>>X>>T;
	int ans=N/X*T;
	if(N%X!=0) {
		ans+=T;
	}
	cout<<ans;
}
