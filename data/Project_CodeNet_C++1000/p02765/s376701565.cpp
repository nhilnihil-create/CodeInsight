#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,R;
	cin>>N>>R;
	if(N<10)
	cout<<100*(10-N)+R;
	else
	cout<<R;
	return 0;
}