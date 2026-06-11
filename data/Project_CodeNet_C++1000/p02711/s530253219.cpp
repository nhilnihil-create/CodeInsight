#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,d;
	string ans="No";
	cin>>N;
	while(N>0){
		d=N%10;
		N=N/10;
		if(d==7){
			ans="Yes";
		}
	}
	cout<<ans;
	return 0;
} 