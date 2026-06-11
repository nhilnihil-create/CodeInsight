#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int d,r,a,b;
	double f;
	cin>>a>>b;
	d=a/b;
	r=a%b;
	f=(double)a/(double)b;
	printf("%d %d %.5lf",d,r,f);
	cout<<endl;
	return 0;
}
