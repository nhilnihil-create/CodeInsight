#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,i;
	cin>>n;
	a=7;
	for(i=1;i<=n;i++){
		a=a%n; 
		if(a==0){
			cout<<i;
			return 0;
		}
		a=a*10+7;
	}
	cout<<-1;
	return 0;
}