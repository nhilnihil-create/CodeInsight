#include<iostream>
#include<math.h>

using namespace std;

int main(){

	int n; cin >> n;
	int total = n + pow(n,2) + pow(n,3);
	printf("%d\n",total);



	return 0;
}