#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	for(double i=1;i<=n;i++){
		int now=(i*1.08);
		if(now==n){
			cout<<int(i)<<endl;
			return 0;
		}
	}
	cout<<":("<<endl;
	return 0;
}