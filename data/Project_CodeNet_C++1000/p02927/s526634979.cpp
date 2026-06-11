#include <bits/stdc++.h>

using namespace std;

bool pr[110];
vector<int> prime;

void sieve(){
	memset(pr, true, sizeof(pr));
	pr[0] = pr[1] = false;
	for(int i = 2; i * i <= 110; i++){
		if(pr[i]){
			for(int j = 2 * i; j <= 110; j += i) pr[j] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int M, D;
	cin >> M >> D;

	sieve();
	int cnt = 0;
	for(int i = 1; i <= M; i++){
		if(pr[i]) continue;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				if(j > 9 || j < 2 || i / j > 9 || i / j < 2) continue;
				int num1 = j;
				int num2 = i / j;
				if(num1 * 10 + num2 <= D) cnt++;
				if(num1 == num2) continue;
				if(num2 * 10 + num1 <= D) cnt++;
			}
		}
	}

	cout << cnt << endl;
}