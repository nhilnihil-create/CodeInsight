#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int x;


	for (int i = 0;; i++){
		cin >> x;
		if (x == 0)break;
		cout << "Case " << i+1 << ": " << x << "\n";
	}
}