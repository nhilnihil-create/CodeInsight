#define	_USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
using namespace std;
int main(){
	
	bool p[5000000]={false};
	
	p[2]=true;
	
	for(int i=3;i<=5000000;i+=2){
		bool f=false;
		for(int j=3;j<=sqrt(i);j+=2){
			if(i%j==0){
				f=true;
				break;
			}
		}
		if(!f)
			p[i]=true;
	}
	long long n;
	
	while(cin>>n,n!=0){
		long long count=0;
		for(int i=n+1;i<=n*2;i++){
			if(p[i])
				count++;
		}
		cout<<count<<endl;
	}
	



}