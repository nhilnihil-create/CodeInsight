#include<iostream>
using namespace std;

#define MAX_N 1000000

int bit[MAX_N],n,m,a,b,c;

int sum(int i){
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

int add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		if(a==0){add(b,c);}
		if(a==1){cout<<sum(c)-sum(b-1)<<endl;}
	}
	return 0;
}