#include <iostream>

using namespace std;

int main(){

	int i, j, n, q, count = 0;
	int dataS[10000], dataT[500];
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> dataS[i];
	}

	cin >> q;
	for (i = 0; i < q; i++){
		cin >> dataT[i];
	}
	for (int j = 0; j < q; j++){
		for (int i = 0; i < n; i++){
			if (dataT[j] == dataS[i]){
				count++;
				break;
			}
		}
	}
	cout << count << "\n";

	return 0;
}