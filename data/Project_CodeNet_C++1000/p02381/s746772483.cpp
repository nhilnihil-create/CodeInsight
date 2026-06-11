#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(){
	
	while(1){
		int n;
		cin >> n;
		
		if(n == 0) break;
		
		int score[n];
		double s_total = 0;
		
		for(int i = 0;i < n; i++){
			cin >> score[i];
			s_total += score[i]; 
		}
		double s_ave = s_total / n; 
		
		double sum = 0;
		for(int i = 0;i < n; i++){
			sum += (score[i] - s_ave) * (score[i] - s_ave);
		}
		double ans = sqrt(sum / n);
		
		cout << fixed << setprecision(5) << ans << endl;
		
	}
	
	return 0;
}