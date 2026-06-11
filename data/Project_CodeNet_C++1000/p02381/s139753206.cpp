#include "bits/stdc++.h"
using namespace std;

int main() {

	while(1){
		double a=0.0,sum=0.0,sumv=0.0;
		double aa[1002];
		cin>>a;
		if(a==0)return 0;
		for (int i = 0; i < a; ++i) {
			cin>>aa[i];
			sum+=aa[i];
		}
		for (int i = 0; i < a; ++i) {
					sumv+=(aa[i]-sum/a)*(aa[i]-sum/a);
		}
		printf("%.10f\n",sqrt(sumv/a));
	}
}