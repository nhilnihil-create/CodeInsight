#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<list>
#include<cctype>
#include<utility>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<double>x(n),y(n);
	for(int i=0;i<n;i++)
		cin >> x[i];
	for (int i = 0; i < n; ++i)
		cin >> y[i];

	for(int i=1;i<=3;i++){
		double ret=0;
		for(int j=0;j<n;j++){
			ret += pow(abs(x[j]-y[j]),i);
		}
		printf("%.10f\n",pow(ret,1./i));
	}

	double ret = 0;
	for(int i=0;i<n;i++)
		ret = max(ret,abs(x[i]-y[i]));
	printf("%.10f\n",ret);


    return 0;
}