#include<iostream>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
	int n,x;
	cin >>x>>n;
	int p[n+2];
	int *q=p;
	*q=-2;
	p[n+1]=102;
	int in;
	rep(i,n){
		cin >>in;
		for(q=p+i;*q>in;*(q+1)=*q,q--);
		*(q+1)=in;	
	}
	q=p;
	int place=-1;
	rep(i,n){
		q++;
		if(*q==x)place=i+1;
	}
	if(place==-1){
		cout<<x;
		return 0;
	}
	int back=place-1,front=place+1;
	int backx=x-1,frontx=x+1;
	while(1){
		if(p[back]!=backx){
			cout << backx;
			return 0;
		}
		if(p[front]!=frontx){
			cout << frontx;
			return 0;
		}
		back--;
		backx--;
		front++;
		frontx++;
	}
}