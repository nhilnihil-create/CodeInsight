#include<iostream>
#include<algorithm>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int K,X;


int main()
{
	ios;
	cin>>K>>X;
	if((K*500)>=X) cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
	return 0;
}