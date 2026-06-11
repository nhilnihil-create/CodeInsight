#include<bits/stdc++.h>
using namespace std;
long long f(long long a,long long b){
	if(a<b) swap(a,b);
	while(b){
		long long t=a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	long long a,b;
	cin>>a>>b;
	long long lcd = f(a,b);
	long long ret = 0;
	for(long long i=2; i*i<=lcd; i++){
		if(lcd%i==0){
			ret++;
			while(lcd%i==0) lcd/=i;
		}
	}
	if(lcd!=1) ret+=2;
	else ret++;
	cout<<ret;
}