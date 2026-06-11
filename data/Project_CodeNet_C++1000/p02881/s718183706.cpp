#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;

long long n,a,b;

int main(){
	cin>>n;
	long long t=sqrt(n);
	int r=t;
	for (int i=r;i>=1;i--){
		if (n%i==0){
			a=i;
			b=n/a;
			break;
		}
	}
	cout<<(a+b-2);
	return 0;
}
