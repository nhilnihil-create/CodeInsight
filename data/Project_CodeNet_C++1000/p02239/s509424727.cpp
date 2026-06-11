#include <iostream>
using namespace std;

const long N = 100;
long M[N + 1][N + 1];
long d[N + 1];
long n;
const long INFTY = 101;

long solve(long id, long dist){
	if (id == 1) d[1] = 0;
	for (long i = 2; i <= n; i++){
		if (M[id][i]){
			if (dist + 1 < d[i]){
				d[i] = dist + 1;
				solve(i, dist + 1);
			} 
		}
	}
}

int main(){
	cin >> n;
	for (long i = 1; i <= n; i++){
		d[i] = INFTY;
		for (long j = 1; j <= n; j++){
			M[i][j] = 0;
		}
	}
	for (long i = 0; i < n; i++){
		long v, k;
		cin >> v >> k;
		for (long j = 0; j < k; j++){
			long nh;
			cin >> nh;
			M[v][nh] = 1;
		}
	}
	solve(1, 0);
	for (long i = 1; i <= n; i++){
		if (d[i] == INFTY) d[i] = -1;
		cout << i << " " << d[i] << endl;
	}
	return 0;
}