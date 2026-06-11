#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double sum=0,sum2=0,temp;
	int n;
	while(1) {
		cin >> n;
		if(n==0) break;
		sum=0.0;
		sum2=0.0;
		for(int i=0;i<n;++i) {
			cin >> temp;
			sum+=temp;
			sum2+=temp*temp;
		}
		cout << fixed << setprecision(8);
		cout << pow(sum2/(double)n - (sum/(double)n)*(sum/(double)n),0.5) << endl;
	}
	return 0;
}