#include<iostream>
using namespace std;

int main(){

	int n; cin >> n;
	int change = (n%1000)?(1000 - (n%1000)):0;
	printf("%d\n",change);


	return 0;
}