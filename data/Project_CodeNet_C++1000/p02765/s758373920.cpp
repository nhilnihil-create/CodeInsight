#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,R;
	cin>>N>>R;
	if(N>=10){
		cout<<R;
	}
	else{
		cout<<100*(10-N)+R;
	}
	return 0;
}