#include <cstdio>
#include <cmath>

int people;
int score[1000];

int main(){	

	while(1){
		int sum =0;
		scanf("%d", &people);
		if(people == 0){
			break;
		}
		for(int i=0; i<people; ++i){
			scanf("%d", &score[i]);
			sum += score[i];
		}
		double mean = 0.;
		double temp = 0.;
		double deviation = 0.;
		double error = 0.;
		
		mean = (double)sum / (double)people;
		
		for(int i=0; i<people; ++i){
			error = (double)score[i] - mean;
			temp += error*error;
		}	
		deviation = sqrt(temp / (double)people);		
		printf("%.8lf\n", deviation);
	}
	
}
