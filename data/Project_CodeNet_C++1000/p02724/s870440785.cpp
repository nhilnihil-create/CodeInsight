#include<iostream>
using namespace std;

int main(void){
	long x;
	cin >> x;
	long sum=0;
	sum+=(x/500)*1000;
	x%=500;
	sum+=(x/5)*5;
	cout << sum << endl;
}