#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MOD = 2019;

int main(){
	string S;
	cin >> S;

	const int N = S.size();
	map<int, int> m;
	int sum[N + 1] = {0};
	m[0]++;
	{
		int tenpow = 1;
		for (int i = N - 1; i >= 0; i--){
			sum[i] = (sum[i + 1] + (S[i] - '0') * tenpow) % MOD;
			m[sum[i]]++;
			tenpow = (tenpow * 10) % MOD;
		}
	}

	int count = 0;
	for(auto t : m){
		if(t.second > 1){
			count += t.second * (t.second - 1) / 2;
		}
	}

	cout << count << endl;
	return 0;
}
