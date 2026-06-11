#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
double ans;
int main(){
	cin >> a >> b;
	ans=(double)a/b;
	cout << a/b <<' '<< a%b <<' ';
	printf("%.10lf\n",ans);
	return 0;
}