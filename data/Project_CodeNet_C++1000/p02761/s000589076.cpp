#include <bits/stdc++.h>
using namespace std;


int pow(int A, int P){
	int a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	int adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	int N, M;
	cin >> N >> M;
	int s[M], c[M];
	for(int i=0;i<M;i++){
		cin >> s[i] >> c[i];
	}
	int MA = pow(10, N);
	int MI = pow(10, N-1);
	int ans = -1;
	if(MI == 1)MI = 0;
	for(int i=MI;i<MA;i++){
		bool chk = true;
		for(int j=0;j<M;j++){
			int tmp = i;
			for(int k=1;k<N + 1-s[j];k++){
				tmp /= 10;
			}
			tmp %= 10;
			if(tmp != c[j]){
				chk = false;
				break;
			}
		}
		if(chk){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}