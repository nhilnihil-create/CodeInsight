#include<bits/stdc++.h>
using namespace std;
int X,Y;
int main()
{
	cin>>X>>Y;
	int sum=0;
	if(X<=3) sum+=3-X+1;
	if(Y<=3) sum+=3-Y+1;
	if(X==1&&Y==1) sum+=4;
	if(sum==0) cout<<"0"<<endl;
	else cout<<sum<<"00000"<<endl;
}