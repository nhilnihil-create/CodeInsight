#include<iostream>
#include<math.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define lrep(i,n) for(long int i=0;i<(n);i++)
using namespace std;
int main(){
	double a;
	cin >>a;
	string b;
	cin >>b;
	unsigned long long int c=a,d=b[0]*100+b[2]*10+b[3]-111*'0';
	cout<<(c*d/100);
}