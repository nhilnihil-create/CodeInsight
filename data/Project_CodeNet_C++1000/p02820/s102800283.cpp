#include <iostream>
#include <vector>
using namespace  std;

int main() {
	int N, K, R, S, P;
	string T;
	long int score=0;
	cin >> N >> K;
	cin >> R >> S >> P;
	cin >> T;

	vector<vector<string>> data(K,vector<string>((int)2 + N/K));
	for (int i = 0; i < N; i++) {
		data.at(i % K).at((int)i/K)=T[i];
	}
	bool counter=true;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < (int) (N + K - i%K) / K; j++) {
			if (data.at(i).at(j) == "r" && counter == true) {
				score += P;
			}
			else if (data.at(i).at(j) == "s" && counter == true) {
				score += R;
			}
			else if(data.at(i).at(j) == "p" && counter == true){
				score += S;
			}

			if ( data.at(i).at(j) == data.at(i).at(j + 1) && counter == true) {
				counter = false;
			}
			else {
				counter = true;
			}
		}
		counter = true;
	}
	cout << score << endl;
	return 0;
}