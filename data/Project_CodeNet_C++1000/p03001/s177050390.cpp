#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int W,H,x,y;
	scanf("%d %d %d %d",&W,&H,&x,&y);

	printf("%.15lf %d\n",((double)W*(double)H)/2.0,2*x == W && 2*y == H);

	return 0;
}
