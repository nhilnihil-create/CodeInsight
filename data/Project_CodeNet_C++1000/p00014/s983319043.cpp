#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<complex>
#include<stack>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)


int main(){
	
	int in;
	while(scanf("%d",&in)!=EOF){
		
		int sum = 0;
		int d = in;
		for(int i=0;i<600;i+=d){
			sum += i*i*d;
		}
		printf("%d\n",sum);
	}
}