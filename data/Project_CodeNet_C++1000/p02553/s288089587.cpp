#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	long long int a,b,c,d,z[4]={0};
	cin>>a>>b>>c>>d;
	z[0]=a*c;
	z[1]=a*d;
	z[2]=b*c;
	z[3]=b*d;
	long long int sum=-1000000000000000000;
	for(int i=0;i<4;i++){
		if(z[i]>sum){
			sum=z[i];
		}
	}
	cout<<sum;
	return 0;
}
