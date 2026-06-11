#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	double sum1=0, sum2=0, sum3=0;
	double d1, d2, d3, d4;
	int i;
	
	cin >> n;
	int x[n], y[n];
	
	for(i=0;i<n;i++)
		cin >> x[i];
	for(i=0;i<n;i++)
		cin >> y[i];
	
	for(i=0;i<n;i++){
		sum1+=fabs((double)x[i]-(double)y[i]);
		sum2+=pow((double)x[i]-(double)y[i], 2.0);
		sum3+=pow(fabs((double)x[i]-(double)y[i]), 3.0);
	}
	
	d4=fabs((double)x[0]-(double)y[0]);
	for(i=1;i<n;i++){
		d4=max(d4, fabs((double)x[i]-(double)y[i]));
	}
	
	d1=sum1;
	d2=sqrt(sum2);
	d3=pow(sum3, 1.0/3.0);
	
	cout << fixed << setprecision(5) << d1 << endl;
	cout << fixed << setprecision(5) << d2 << endl;
	cout << fixed << setprecision(5) << d3 << endl;
	cout << fixed << setprecision(5) << d4 << endl;
	
	return 0;
}