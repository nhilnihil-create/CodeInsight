#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
	long long c=a%b;
	if(c) return gcd(b,c);
	else return b;
}
int main(){
	long long x;
	cin>>x;
	x=360/gcd(360,x);
	cout<<x<<endl;
}