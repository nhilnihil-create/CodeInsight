#include <iostream>
using namespace std;

int main() {
	int N, subans, ans;
	cin >> N;
	int H[N+1];
	for(int k = 0; k < N; k++){
		cin >> H[k];
	}
	H[N] = 1000000002;
	subans = 0;
	ans = 0;
	for(int i = 0; i < N; i++){
		if(H[i+1] <= H[i]){
			subans++;
		}else{
			if(ans < subans){
				ans = subans;
			}
			subans = 0;
		}

	}
	cout << ans << endl;

	return 0;
}