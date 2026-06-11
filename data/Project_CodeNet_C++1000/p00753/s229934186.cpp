#include <iostream>
#include <cmath>
using namespace std;

const int N = 123456;

int p[2 * N + 1];
int main(){
	int n;
	p[0] = p[1] = 0;
	for(int i = 2;i <= 2 * N;++i){
		p[i] = 1;
	}
	for(int i = 2;i <= sqrt(2 * N);++i){
		if(p[i]){
			for(int j = i + i;j <= 2 * N;j += i){
				p[j] = 0;
			}
		}
	}
	for(int i = 3;i <= 2 * N;++i){
		p[i] += p[i - 1];
	}
	while(cin >> n, n){
		cout << p[2 * n] - p[n] << endl;
	}
	return 0;
}