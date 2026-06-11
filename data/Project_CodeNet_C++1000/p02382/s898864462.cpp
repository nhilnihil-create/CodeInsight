#include <bits/stdc++.h>
using namespace std;
int n;
vector<double> x,y;

double distance1(){
	double sum=0.0;
	for(int i=0;i<n;i++){
		sum+=abs(x[i]-y[i]);
	}
	return sum;
}

double distance2(){
	double sum;
	for(int i=0;i<n;i++){
		sum+=(x[i]-y[i])*(x[i]-y[i]);
	}
	return sqrt(sum);
}

double distance3(){
	double sum;
	for(int i=0;i<n;i++){
		sum+=(x[i]-y[i])*(x[i]-y[i])*abs(x[i]-y[i]);
	}
	return cbrt(sum);
}

double distanceI(){
	double m=0;
	for(int i=0;i<n;i++){
		m=max(m,abs(x[i]-y[i]));
	}
	return m;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		double X;
		cin>>X;
		x.push_back(X);
	}for(int i=0;i<n;i++){
		double Y;
		cin>>Y;
		y.push_back(Y);
	}
	cout<<fixed;
	cout<<distance1()<<endl;
	cout<<distance2()<<endl;
	cout<<distance3()<<endl;
	cout<<distanceI()<<endl;
	return 0;
}

