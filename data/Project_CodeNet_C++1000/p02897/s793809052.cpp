#include <iostream> 
 
using namespace std; 
 
int main(){ 
	int n;
	cin >> n;
	int odd = 0;
	int eve = 0;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0) eve++;
		else odd++;
	}
	cout << (double)(odd) / (double)(odd+eve) << endl;
} 
