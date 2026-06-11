#include<bits/stdc++.h>
#include <time.h>
using namespace std;
#include <math.h>
#define ll long long 
// to increase precision
// std::cout<<std::fixed;
// 	std::cout<<std::setprecision(6)<<z;
//clock_t tStart = clock();
//printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define max1 200001


int main(){	
	
	int x;
	cin>>x;
	for(int i=-200;i<=200;i++){
		int ansf=0;
		for(int j=-200;j<i;j++){
			long long int a=(long long)pow(i,5);
			long long int b=(long long)pow(j,5);
			if(a-b==x){
				cout<<i<<" "<<j<<endl;
				ansf=1;
				break;
			}
		}
		if(ansf)
			break;
	}
	
}