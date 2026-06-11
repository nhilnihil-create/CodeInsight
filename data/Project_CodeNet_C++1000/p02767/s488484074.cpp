#include <cstdio>
#include <algorithm>
#define f1(i,n) for(int i=0;i<(int)n;i++)
const int inf = 1000000000;
using namespace std;
int main(){
	int n;scanf("%d",&n);
	int arr[n];
	f1(i,n){
			scanf("%d",&arr[i]);
		}
	int ans = inf;
	for(int i=1;i<=100;i++){
			int cost = 0;
			f1(j,n)cost += (arr[j]-i)*(arr[j]-i);
			ans = min(ans,cost);
		}
	printf("%d",ans);		
	return 0;
	}


