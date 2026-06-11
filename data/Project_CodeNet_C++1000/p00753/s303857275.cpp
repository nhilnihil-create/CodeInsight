#include <iostream>
#include <cmath>
using namespace std;

const int N = 123456;
int p[2 * N + 1];

int main(){
	for(int i = 0;i <= 2 * N;++i){
		p[i] = i;
	}
	for(int i = 2;i <= sqrt(2 * N);++i){
		if(p[i]){
			for(int j = i + i;j <= 2 * N;j += i){
				p[j] = 0;
			}
		}
	}
	p[1] = 0;
	int n;

	while(cin >> n, n){
		int c = 0;
		for(int i = n + 1;i <= n + n;++i){
			if(p[i]) ++c;
		}
		cout << c << endl;
	}
	return 0;
}