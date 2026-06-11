#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int M = 1e6;
int p[M + 1];

int main(){
	int a, d, n;
	fill(p, p + M + 1, 1);
	p[0] = p[1] = 0;
	for(int i = 2;i < sqrt(M + 1);++i){
		if(p[i]){
			for(int j = i + i;j <= M;j += i){
				p[j] = 0;
			}
		}
	}
	while(cin >> a >> d >> n, a){
		int c = 0, t;
		for(t = a;c < n;t += d){
			c += p[t];
		}
		cout << t - d << endl;
	}
	return 0;
}