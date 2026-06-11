#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int ret = 0;
	while(n){
		ret++;
		n/=k;
	}
	cout<<ret;
}