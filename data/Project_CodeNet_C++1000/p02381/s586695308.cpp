#include<string>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdio>

using namespace std;

double sum(int n,int *a){
	int i;
	double sum=0;
	for(i=0;i<n;i++){
		sum+=a[i];
		}
	return sum;
	}


int main()
{

	while(1){
		int c;
		cin >> c;
		if(c==0) break;	
		else{
		int *a;
		a=new int[c];
		int i; 
		for(i=0;i<c;i++){
			cin >> a[i];
			}
			
		double mean=sum(c,a)/c;
		int *b;
		b=new int[c];
		for(i=0;i<c;i++){
			b[i]=pow(a[i],2);
			}
		double mean2=sum(c,b)/c;
		
		printf("%lf\n",sqrt(mean2-pow(mean,2)));
		}
	}		
	return 0;
}