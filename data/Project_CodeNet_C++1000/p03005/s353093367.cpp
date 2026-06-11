#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,k;
	cin>>N>>k;
	if(k==1)
	{
		cout<<"0";
		return 0;
	}
	cout<<N-k;
}