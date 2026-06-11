#include<iostream>
#include<cmath>
#include <algorithm>
using namespace std;
vector<int> disx;
vector<int> disy;
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		disx.push_back(x+y);
		disy.push_back(x-y);
	}
	sort(disx.begin(),disx.end());
	sort(disy.begin(),disy.end());
	int d1=disx.back()-disx.front();
	int d2=disy.back()-disy.front();
	printf("%lld",max(d1,d2));
	return 0;
} 
