#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
	return (a > b);
}

int s[10000];

int main(){
	while(true){
		int a,b,c,d,e,f;
		cin >> a >> b >> c;
		if(a==0&&b==0&&c==0){
			break;
		}
		for(int n=0;n<a;n++){
			cin >> d;
			s[n]=d;
		}
		sort(s,s+a, compare);
		a=0;
		for(int m=b;m<=c;m++){
			e=s[m-1]-s[m];
			if(a<=e){
				a=e;
				f=m;
			}
		}
		printf("%d\n",f);
	}
}
