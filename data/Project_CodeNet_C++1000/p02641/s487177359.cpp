#include <iostream>

using namespace std;

int main(){
	int X, N;
	cin >> X >> N;

	int p[N];
	for (int i = 0; i < N; i++){
		cin >> p[i];
	}

	int ans = 1e9;
	for (int i = 0; i <= 101; i++){
		bool skip = false;
		for (int j = 0; j < N; j++){
			if(i == p[j]){
				skip = true;
				break;
			}
		}
		if(skip){
			continue;
		}

		if (abs(i - X) < abs(ans - X))
		{
			ans = i;
		}
		else if (abs(i - X) == abs(ans - X))
		{
			ans = min(ans, i);
		}
	}

	cout << ans << endl;
	return 0;
}
