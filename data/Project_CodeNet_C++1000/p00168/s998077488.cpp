#include<iostream>

using namespace std;

int main(){

	int n;

	int memo[100];

	while(1){

		cin>>n;

		if(n==0) break;

		memo[0]=1;
		memo[1]=1;
		memo[2]=2;
		for(int i=3;i<=n;i++){
			memo[i]=memo[i-1]+memo[i-2]+memo[i-3];
		}
		cout<<memo[n]/365/10+1<<endl;
	}
}