#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	int *x,*y;
	double minkow1=0,minkow2=0,minkow3=0,minkowinf=0;
	
	cin>>n;
	x = new int[n];
	y = new int[n];
	
	for(int i=0;i<n;++i)cin>>x[i];
	for(int i=0;i<n;++i)cin>>y[i];
	
	
	for(int i=0;i<n;++i){
		minkow1 += fabs(x[i]-y[i]);
	}
	
	for(int i=0;i<n;++i){
		minkow2 += (x[i]-y[i])*(x[i]-y[i]);
	}
	minkow2 = sqrt(minkow2);
	
	for(int i=0;i<n;++i){
		minkow3 += pow((fabs(x[i]-y[i])),3);
	}
	minkow3 = pow(minkow3,1.0/3);
	
	for(int i=0;i<n;++i){
		if( fabs(x[i]-y[i]) > minkowinf )minkowinf = fabs(x[i]-y[i]);
	}
	cout<<fixed<<setprecision(6)<<minkow1<<endl<<minkow2<<endl<<minkow3<<endl<<minkowinf<<endl;
}