#include<bits/stdc++.h>
using namespace std;

int main(){
	long long X;
	cin >> X;
	long long a = X/500;
	X=X%500;
	long long b = X/5;
	cout << a * 1000 + b * 5 << endl;

}