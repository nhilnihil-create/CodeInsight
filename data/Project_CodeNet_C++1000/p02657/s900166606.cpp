#include<iostream>
#include<cstring>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int a, b;
	cin >> a >> b;
	cout << a * b;

	return 0;
}