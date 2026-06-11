#include<bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		int a,b,c;
		cin >> a;
		if(a==0)
			{break;}
		int student[a]={};
		for(int n=0;n<a;n++){
			cin >> b;
			student[n]=b;
		}
		sort(student,student+a);
		c=student[0]-student[1];
		for(int m=0;a-1>m;m++){
			if(c<student[m]-student[m+1]){
				c=student[m]-student[m+1];
		}}
		printf("%d\n",c*-1);
}}

