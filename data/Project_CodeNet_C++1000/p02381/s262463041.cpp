#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	int n;
	while(1){
		int s[1000] = {};
		cin >> n;
		if(n==0){
			break;
		}
		else{
			int sum = 0;
			double var, ave;
			for(int i = 0; i < n; i++){
				cin >> s[i];
				sum += s[i];
			}
			ave = double(sum) / n;
			double temp = 0;
			for(int i = 0; i < n; i++){
				temp += (s[i] - ave)*(s[i] - ave);
			}
			var = temp / n;
			printf("%f\n", sqrt(var));
		}
	}

	return 0;
}