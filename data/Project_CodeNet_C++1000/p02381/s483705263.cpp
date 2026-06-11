#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	int s[1000];
	int sum1=0;
	double sum2=0.0;
	double m;
	int i;
	
	while(1){
		cin >> n;
		if(n==0)
			break;
			
		for(i=0;i<n;i++){
			cin >> s[i];
			sum1+=s[i];
		}
		m=(double)sum1/(double)n;
		
		for(i=0;i<n;i++){
			sum2+=(s[i]-m)*(s[i]-m);
		}
		
		cout << fixed << setprecision(4) << sqrt(sum2/n) << endl;
		
		sum1=0;
		sum2=0.0;
	}
	return 0;
}