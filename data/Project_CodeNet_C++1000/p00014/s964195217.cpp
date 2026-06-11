#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int d;
	while(~scanf("%d",&d)){
		int S=0;
		for(int i=d;i<=600-d;i+=d){
			S += (i*i)*d;
		}
		printf("%d\n",S);
	}
}