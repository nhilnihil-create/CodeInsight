#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll; 

int main() {
	int n, ans; 
	cin >> n;
	ans = n%10;
	if(ans == 2 || ans == 4 || ans == 5 || ans == 7 || ans ==9) {
		cout << "hon" << endl;
	} else if(ans == 3) {
		cout << "bon" << endl;
	} else cout << "pon" << endl; 
}
