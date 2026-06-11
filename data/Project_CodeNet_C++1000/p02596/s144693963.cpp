#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x=7,k,i,j;
	cin>>k;
	for(i=1;i<k+10;i++){
		if(x%k==0){
			cout<<i<<endl;
			return 0;
		}
		x%=k;
		x=x*10+7;
	}
	cout<<-1<<endl;
	return 0;
}
