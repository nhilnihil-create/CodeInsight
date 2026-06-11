#include <iostream>
using namespace std;

int main(){
	int n , m;
	cin >> n >> m;

	int sum = 0 , num;
	for(int i = 0; i < m; i++){
		cin >> num;
		sum += num;
	}
	if(n >= sum){
		cout << n - sum << endl;
	}
	else{
		cout << -1 << endl;
	}
}