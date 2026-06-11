#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,k;
int main(){
	cin>>a>>b>>c>>k;
	cout<<min(a,k)-max(k-b-a,0)<<endl;
	return 0;
}


