#include<bits/stdc++.h>
using namespace std;
int main(){
double sum,y1=1,y2=0;
int n,a[105];
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i];
	//y3+=a[i];
	y1*=a[i];	
}
  for(int i=0;i<n;i++){
		y2+=y1/a[i];	
}
sum=y1/y2;
printf("%.6f",sum);
return 0;
}