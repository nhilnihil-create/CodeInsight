#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
typedef long long ll;
using namespace std;

int used[100010];

int main(){
	int N; cin >> N;
	if(N == 1){ cout << "No" << "\n"; return 0; }
	if(N == 6){
		cout << "Yes" << "\n";
		cout << 3 << " " << 5 << "\n";
		cout << 4 << " " << 5 << "\n";
		cout << 4 << " " << 2 << "\n";
		cout << 9 << " " << 2 << "\n";
		cout << 9 << " " << 11 << "\n";
		cout << 10 << " " << 11 << "\n";
		cout << 10 << " " << 8 << "\n";
		cout << 1 << " " << 5 << "\n";
		cout << 7 << " " << 4 << "\n";
		cout << 4 << " " << 6 << "\n";
		cout << 2 << " " << 12 << "\n";
		return 0;
	}
	if(N % 4 == 1){
		cout << "Yes" << "\n";
		cout << 1 << " " << 2 << "\n";
		cout << N+1 << " " << 3 << "\n";
		cout << N+2 << " " << N << "\n";
		rep(i, N-2){
			cout << 2+i << " " << 3+i << "\n";
			cout << 2+i+N << " " << 3+i+N << "\n";
		}
	}else if(N % 4 == 3){
		cout << "Yes" << "\n";
		rep(i, 2*N-1){
			cout << i+1 << " " << i+2 << "\n";
		}
	}else{
		int n = N, f = 0;
		int ch;
		for(int i=0; f == 0; i++){
			if(N & (1<<i)){ ch = (1<<i); f = 1; n -= (1<<i); }
		}
		if(n == 0){
			cout << "No" << endl;
			return 0;
		}
		cout << "Yes" << "\n";
		cout << N << " " << ch << "\n";
		cout << n << " " << ch << "\n";
		cout << 2*N << " " << n << "\n";
		int pr = -1;
		if((N-1) % 4 == 1){
			int p = (ch+2)/4, q = (n+2)/4;
			for(int i=1; i<=(N-2)/4; i++){
				if(i == p || i == q){
					rep(j, 3){
						cout << 4*i-2+j << " " << 4*i-1+j << "\n";
						cout << 4*i-2+j+N << " " << 4*i-1+j+N << "\n";
					}
					cout << 4*i+1 << " " << 4*i-2+N << "\n";
				}else{
					rep(j, 3){
						cout << 4*i-2+j << " " << 4*i-1+j << "\n";
						cout << 4*i-2+j+N << " " << 4*i-1+j+N << "\n";
					}
					cout << 4*i+1 << " " << 4*i-2+N << "\n";
					if(pr == -1){
						pr = i;
					}else{
						cout << 4*pr+1+N << " " << 4*i-2 << "\n";
						pr = i;
					}
				}
			}
			if(pr != -1){
				cout << N << " " << 4*pr+1+N << "\n";
			}
			cout << 1 << " " << 2 << "\n";
			cout << N+1 << " " << 3 << "\n";
		}else{
			int p = ch/4, q = n/4;
			for(int i=0; i<(N/4); i++){
				if(i == p || i == q){
					rep(j, 3){
						if(i != 0 || j != 0){
							cout << 4*i+j << " " << 4*i+1+j << "\n";
							cout << 4*i+j+N << " " << 4*i+1+j+N << "\n";
						}
					}
					if(i != 0){
						cout << 4*i+3 << " " << 4*i+N << "\n";
					}else{
						cout << 3 << " " << N+1 << "\n";
					}
				}else{
					rep(j, 3){
						if(i != 0 || j != 0){
							cout << 4*i+j << " " << 4*i+1+j << "\n";
							cout << 4*i+j+N << " " << 4*i+1+j+N << "\n";
						}
					}
					if(i != 0){
						cout << 4*i+3 << " " << 4*i+N << "\n";
					}else{
						cout << 3 << " " << N+1 << "\n";
					}
					if(pr == -1){
						pr = i;
					}else{
						cout << 4*pr+3+N << " " << 4*i << "\n";
						pr = i;
					}
				}
			}
			if(pr != -1){
				cout << N << " " << 4*pr+3+N << "\n";
			}
		}
	}
	return 0;
}
