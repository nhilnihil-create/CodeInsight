#include <iostream>
using namespace std;
int main(){
	int N, n, t, ans;
	while (cin >> N, N){
		n = N / 2;
		ans = 0;
		for (int i = 1; i < n + 1; ++i){
			t = i;
			for (int j = 1; j < n + 1; ++j){
				t += i + j;
				if (t == N) ans++;
				else if (t > N) break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}