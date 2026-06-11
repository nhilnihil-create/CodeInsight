#include <bits/stdc++.h>
using namespace std;

int N, K, result;
char S[100010];

int main(){
	cin >> N >> K >> S;
	result = 0;
	for (int i = 1; i < N; i++)
		result += (S[i] == S[i - 1]);
	result = min(result + 2 * K, N - 1);
	cout << result << endl;
}