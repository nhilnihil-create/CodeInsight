#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int M=1e9+7;
int main(){
	
	int n,x,t;
	cin>>n>>x>>t;
	if(n%x==0)
	cout<<((n/x))*t;
else cout<<(n/x + 1)*t;
	return 0;
}