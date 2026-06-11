#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <complex>
#include <vector>
#include <functional>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define INF 100000000
typedef pair<int,int> P;
int coin[]={500,100,50,10,5,1};
int main()
{
	int n;
	while(scanf("%d",&n)&&n){
		int ans=0;
		n=1000-n;
		for(int i=0;i<6;i++){
			ans+=n/coin[i];
			n%=coin[i];
		}
		printf("%d\n",ans);
	}
    return 0;
}