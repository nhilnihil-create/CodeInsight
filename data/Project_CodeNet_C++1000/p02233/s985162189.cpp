#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define VIEW(dat) for(auto v : dat){cout<<v<<endl;}

int dat[45];
int count;
int fib(int n){
	if(n<2){
		return 1;
	}else{
		if(dat[n]) return dat[n];
		dat[n]=fib(n-1)+fib(n-2);
		return dat[n];
	}
}

int main(){
	count=0;
	rep(i,45) dat[i]=0;	
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}