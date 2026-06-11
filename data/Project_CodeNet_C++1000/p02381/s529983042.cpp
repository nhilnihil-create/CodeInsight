#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int main(){
	int n, s;
	while(1){
		cin>>n;
		if(n == 0) break;

		vector<int> score;
		double m = 0, a = 0;
		
		for(int i=0;i<n;i++){
			cin>>s;
			score.push_back(s);
			m += s;
		}
		m /= n;

		for(int i=0;i<n;i++){
			a += pow(score[i]-m, 2);
		}
		a /= n;

		printf("%.8lf\n", sqrt(a));
	}
	return 0;
}