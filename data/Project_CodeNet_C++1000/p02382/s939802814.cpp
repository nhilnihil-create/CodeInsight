#include <bits/stdc++.h>
using namespace std;

int main(){
	int x[101],y[101];
	int n, i;
	double p = 0, D = 0;

	cin>>n;
	for(i = 0;i < n;i++)
		cin>>x[i];

	for(i = 0;i < n;i++)
		cin>>y[i];

	for(i = 0;i < n;i++)
		p += (double)abs(x[i]-y[i]);

		printf("%7lf\n",p);

		p = 0;

	for(i = 0;i < n;i++)
		p += pow(((double)abs(x[i]-y[i])),2);

		D = sqrt(p);
		printf("%7lf\n",D);

		p = 0;

	for(i = 0;i < n;i++)
		p += pow(((double)abs(x[i]-y[i])),3);

		D = pow(p,1.0/3.0);
		printf("%7lf\n",D);

		p = 0;

	for(i = 0;i < n;i++)
		if(i == 0)
			D = abs(x[0]-y[0]);

		else
			D = max(D,(double)abs(x[i]-y[i]));
		printf("%7lf\n",D);

	return 0;
}