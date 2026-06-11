#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<fixed<<setprecision(12);
	
	int n, x[100], y[100];
	double p1 = 0, p2 = 0, p3 = 0, pi = 0, temp;
	
	cin>>n;
		
	for(int i = 0; i < n; i++)  cin>>x[i];
	for(int i = 0; i < n; i++)  cin>>y[i];
	
	pi = fabs(x[0] - y[0]);

	for(int i = 0; i < n; i++){
		temp = fabs(x[i] - y[i]);
		p1 += temp;
		p2 += pow(temp, 2);
		p3 += pow(temp, 3);
		if(pi < temp) swap(pi, temp);
	}
	
	p2 = pow(p2, 1.0/2.0);
	p3 = pow(p3, 1.0/3.0);
	
	cout<<p1<<endl<<p2<<endl<<p3<<endl<<pi<<endl;

	return 0;
}
