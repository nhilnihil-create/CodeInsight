#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <limits.h>
using namespace std;
int N;
long long int K;
int P[5001];
long long int C[5001];
long long int Max=LLONG_MIN;
int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++)cin >> P[i];
	for(int i=1;i<=N;i++)cin >> C[i];

	for(int i=1;i<=N;i++){
		//printf("i=%d\n",i);
		int start =i;
		int now=0;
		long long int cy_sum=0;
		long long int cy_len=0;
		//cy_sum = C[start];
		while(start!=now){
			if(now == 0)now = P[start];
			else now=P[now];
			cy_sum += C[now];
			cy_len++;
		}
		start =i;
		now=P[start];
		//printf("len=%lld\n",cy_len);
		//printf("sum=%lld\n",cy_sum);
		
		long long int Sum=0;
		
		//printf(" d = %d Cycle_d_Sum = %lld\n",d,d*cy_sum);
		//if(d>0)Max = max(Max,Sum+(d-1)*cy_sum);
		for(int j=1;j<=cy_len && j<=K;j++){
			Sum+=C[now];
			Max = max(Sum,Max);
			//printf("j= %d start = %d now = %d Sum =%lld Max = %lld\n",j,start,now,Sum,Max);
			long long int d = (K-j)/cy_len;
			Max = max(Max,Sum+d*cy_sum);
			now = P[now];
		}
		//printf("Max = %lld\n",Max);
		
	}
	cout << Max << endl;
	return 0;
}
