#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
int main()
{
	cin>>n>>a>>b;
	if(a==b){
		cout<<"0"<<endl;
		return 0;
	}
	if((b-a)%2==0)
	{
		cout<<(b-a)/2<<endl;
		return 0;
	}
	cout<<min(a-1,n-b)+(b-a)/2+1<<endl;
	
}