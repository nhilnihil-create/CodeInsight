#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n){
		int s[n];
		double sum=0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			sum+=s[i];
		}
		double ave=sum/n;
		sum=0.0;
		for(int i=0;i<n;i++) sum+=(s[i]-ave)*(s[i]-ave);
		cout<<sqrt(sum/n)<<endl;
		cin>>n;
	}
	return 0;
}

