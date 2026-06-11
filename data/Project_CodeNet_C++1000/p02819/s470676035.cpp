#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int prime(int n)
{
	if(n<2) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	int i;
	for(i=3; i<=sqrt(n); i=i+2){
		if(n%i==0) return 0;
	}
	return 1;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while(!prime(n)){
		n++;
	}
	cout << n << endl;
	return 0;
}
