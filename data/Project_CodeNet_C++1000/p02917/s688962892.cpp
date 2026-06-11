#include<iostream>
using namespace std;

int main()
{
	int n,b[100],i,ans=0,num=100000;

	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>b[i];

		if(num<b[i]){
			ans+=num;
		}else{
			ans+=b[i];
		}

		num=b[i];
	}

	ans+=num;

	cout<<ans<<endl;

	return 0;
}