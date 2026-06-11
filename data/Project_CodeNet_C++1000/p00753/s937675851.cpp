#include <iostream>
using namespace std;
bool tf[123456 * 2 + 1] = { false };

void CheckList(){
	for (int i = 2; i <= 123456 * 2; i++){
		if (tf[i]) continue;
		for (int j = i * 2; j <= 123456 * 2; j += i){
			tf[j] = true;
		}
	}
}

int main(){
	int n;
	CheckList();
	while (1){
		cin >> n;
		if (n == 0) break;
		int n2 = n * 2;
		int count = 0;
		for (int i = n + 1; i <= n2; i++){
			if (!tf[i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}