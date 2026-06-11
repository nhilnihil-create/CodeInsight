#include <iostream>
using namespace std;

int solution(const int& N, const int& K){
			
	if(K == 1) return 0;
	if(N == K) return 0;
	//K > N
	return (N - K);
		
}

int main() {
	int N, K;
	//N: ball
	//K: people
	cin >> N >> K;
	//N > K

	cout << solution(N, K) << endl;	
	return 0;
}