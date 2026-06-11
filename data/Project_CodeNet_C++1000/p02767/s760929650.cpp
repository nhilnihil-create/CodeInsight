#include <bits/stdc++.h>
using namespace std;

int x[102];
int main() {
	// your code goes here
	int n; 
	while(scanf("%d",&n)==1){
	
		int sum = 0; 
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
			sum+=x[i];
		}
		
		sort(x,x+n);
		//int avg = sum/n;
		int avg = (int)round((sum*1.0)/(n*1.0));
		//int median = (n&1) ? x[n/2] : (x[n/2] + x[n/-1])/2;
		int total_cost = 0;
		for(int i=0;i<n;i++){
			//int cost = x[i]-median;
			int cost = x[i]-avg;
			total_cost+=cost*cost;
		}
		
		printf("%d\n", total_cost);
	}
	return 0;
}