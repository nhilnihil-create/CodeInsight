#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int main(void){
	int M,D,count=0,a=0,b=0;
	cin>>M>>D;
	a=D/10;
	b=D-a*10;
	for(int i=1;i<=M;i++)
	{
		for(int j=2;j<=(D/10);j++){
			if((i%j==0&&i/j<=9&&2<=i/j)&&(j!=(D/10)||i/j<=(b)))
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}