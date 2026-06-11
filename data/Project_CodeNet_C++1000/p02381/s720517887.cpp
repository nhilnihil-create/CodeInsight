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
		double mean = (double)sum / (double)people;;
		double temp = 0.;
		
		for(int i=0; i<people; ++i){
			double error = (double)score[i] - mean;
			temp += error*error;
		}
		double deviation = sqrt(temp / (double)people);		
		printf("%.8lf\n", deviation);
	}
}
