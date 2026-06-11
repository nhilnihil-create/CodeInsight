#include<stdio.h>
#include<iostream>
using namespace std;
long long  a,b,c,d ,sum1,sum2,sum; 
int main()
{     
     cin >> a >> b >> c >> d ;
     if(a >= 0 && c >=0)
     {
     	cout << b*d ;
	 }
	 else if(b <= 0 && d <=0)
	 {
	 	cout << a*c;
	 }
	 else 
	 {
	 	sum1 = a*c ,sum2 =b*d;
	 	sum = max(sum1,sum2);
	 	
	 	sum1 = a*d ,sum2 =b*c;
	 	sum = max(sum,max(sum1,sum2));
	 	cout << sum;
	 }
	return 0;
} 