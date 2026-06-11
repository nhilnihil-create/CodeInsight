#include <iostream>
using namespace std;

int main(){
	int n, ans;
	long long int root[40] = {}, day[31] = {};
	root[0] = 1;
	root[1] = 1;
	root[2] = 2;
	for(int i = 3;i<40;i++){
		root[i] = root[i - 1] + root[i - 2] + root[i - 3];
	}
	for(int i = 0;i<40;i++){
		day[i] = root[i] / 10;
		if(root[i] % 10 > 0){
			day[i]++;
		}
	}
	while(cin >> n){
		if (n == 0) break;
		ans = 0;
		if (day[n] > 0) ans++;
		ans += day[n] / 365;
		cout << ans << endl;
	}
	return 0;
}