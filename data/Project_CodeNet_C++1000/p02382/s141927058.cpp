#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
    
int main()
{
	float p1=0,p4=0;
	double p2=0,p3=0;
	int n;
	cin >> n;
	int *x = new int[n];
	int *y = new int[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++) {
		cin >> y[i];
		if (x[i] > y[i])
			x[i] -= y[i];
		else
			x[i] = y[i] - x[i];
		p1 += x[i];
		p2 += pow(x[i],2); 
		p3 += pow(x[i],3);
		if (p4 < x[i])
			p4 = x[i];
	}		
	cout << fixed << setprecision(5)
		 << p1 << endl
		 << sqrt(p2) << endl
		 << pow(p3,1.0/3.0) << endl
		 << p4 << endl;
	delete []x,y;
	return 0;
}