#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define PI 3.14159265
	
int main(void){
	int x[100],y[100];
	double manh=0,euc=0,p_3=0,cheb=0;
	double temp;
	int num;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>x[i];
	}
	for(int i=0;i<num;i++){
		cin>>y[i];
	}
	for(int i=0;i<num;i++){
		temp = abs(x[i]-y[i]);
		manh += temp;
		euc += temp*temp;
		p_3 += temp*temp*temp;
		if(cheb < temp)
			cheb = temp; 
	}
	euc = pow(euc,1/2.0);
	p_3 = pow(p_3,1/3.0);

	cout.precision(8);
	cout<<fixed<<manh*1.0<<endl;
	cout.precision(8);
	cout<<fixed<<euc*1.0<<endl;
	cout.precision(8);
	cout<<fixed<<p_3*1.0<<endl;
	cout.precision(8);
	cout<<fixed<<cheb*1.0<<endl;
	return 0;
}