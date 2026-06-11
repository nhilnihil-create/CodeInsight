#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

const int INF = 100000000;
const int N = 300000;

int Eratos[N];

void era(){
	for(int i=0; i<N; i++){
		Eratos[i] = 1;
	}

	Eratos[0] = Eratos[1] = 0;
	for(int i=2; i<N; i++){
		if(Eratos[i] == 0) continue;
		for(int j=2; i*j < N; j++){
			Eratos[j*i] = 0;
		}
	}
}

int main(void) {
	era();
	while(1){
		int n; 
		cin >> n;
		if(n == 0) break;

		int ans = 0;
		for(int i=n+1; i<=2*n; i++){
			if(Eratos[i] == 1) ans++;
		}
		cout << ans << endl;
	} 
	return 0;
}