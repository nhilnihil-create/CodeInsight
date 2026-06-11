#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	long long int a,b,n;
	cin>>a>>b>>n;
	long long int x;
	if(b-1<=n)x = b-1;
	else x = n;

	cout<<a*x/b<<endl;

	return 0;
}