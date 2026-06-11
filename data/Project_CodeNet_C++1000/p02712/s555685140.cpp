#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 0; i < n+1; i++){
		int num = i;
		if(i % 3 == 0 || i % 5 == 0){
			num = 0;
		}
		ans += num;
	}
	cout << ans << endl;
}