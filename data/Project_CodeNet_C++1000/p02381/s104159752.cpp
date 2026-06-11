#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	double s[1000],a,m;

	while(1){
		cin >> n;
		
		if(n==0)break;

		double all=0,z=0;
		
		for(int i=0; i<n; i++){
			cin >> s[i];
			all += s[i];
		}
		
		m = all/n;

		for(int i=0; i<n; i++){
			z += pow(s[i]-m,2);
		}

		a = sqrt(z/n);

		printf("%f\n",a);
		//printf("test all=%.10f m=%.10f z=%.10f\n",all,m,z); //test
	}

	return 0;
}