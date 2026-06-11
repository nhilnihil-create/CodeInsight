#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll; 


int main(){
	int n,k;
	cin >> n >> k;
	double p[n];
	for(int i=0;i<n;i++)  cin >> p[i];
	double sum[n+1];
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + (p[i-1]+1.0)/2;
	}

	double ans = sum[k];
	for(int i=k+1;i<=n;i++){
		ans = max(ans, sum[i]-sum[i-k]);
	}

	printf("%.7f\n",ans);


	return 0;
}
