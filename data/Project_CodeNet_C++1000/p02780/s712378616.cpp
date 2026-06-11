#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <limits.h>
#include <functional>
using namespace std;
int n,k;
int p[200001];
double ex[200001];
double tmp=0.0;
double ans=0.0;
int main(){
	cin >> n >> k;
	for(int i=0;i<n;i++)cin >> p[i];
	for(int i=0;i<n;i++){
		ex[i] = ((double)p[i]+1.0)/2.0;
	}
	for(int i=0;i<k;i++)tmp+=ex[i];
	ans=max(ans,tmp);
	for(int i=k;i<n;i++){
		tmp-=ex[i-k];
		tmp+=ex[i];
		ans = max(ans,tmp);
	}
	printf("%f\n",ans);
	return 0;
}
