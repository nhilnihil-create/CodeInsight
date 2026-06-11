#include<iostream>
using namespace std;
typedef unsigned long long ull;

ull fact(int n){return n>1?n*fact(n-1):1;}
int main(){
	int n;
	cin>>n;
	cout<<fact(n)<<endl;
}