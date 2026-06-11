#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
int main(){
	int n;
	double o;
	cin>>n;
	if (n%2 == 0){
		o = n/2;
	}
	else{
		o = n/2 + 1;
	}
	cout<<o/n;
	return 0;
}
