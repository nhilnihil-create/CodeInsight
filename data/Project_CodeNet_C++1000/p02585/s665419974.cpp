#include <bits/stdc++.h>
using namespace std;
#define inf -10000000000

long long calc(long long K, vector<int> G, vector<long long> C){
	long long ans = inf;
	long long L = (long long)G.size();
	long long SUM[2 * L + 1];
	SUM[0] = 0;
	for(int i=1;i<=L;i++){
		SUM[i] = SUM[i-1] + C[G[i-1]];
	}
	for(int i=1;i<=L;i++){
		SUM[L+i] = SUM[L+i-1] + C[G[i-1]];
	}
	if(SUM[L] > 0 && K >= L){
		long long sub = SUM[L] * (K / L);
		long long subK = K % L;
		for(int i=0;i<L;i++){
			for(long long t=0;t<=min(subK, L);t++){
				long long tmp = SUM[i + t] - SUM[i];
				// cout << sub + tmp << endl;
				// cout << subK << ":" << sub << ":" << tmp << endl;
				ans = max(sub + tmp, ans);
			}
		}
	}
	if(SUM[L] > 0 && K >= L){
		long long sub = SUM[L] * ((K / L) - 1);
		for(int i=0;i<L;i++){
			for(long long t=0;t<=L;t++){
				long long tmp = SUM[i + t] - SUM[i];
				// cout << sub + tmp << endl;
				// cout << subK << ":" << sub << ":" << tmp << endl;
				ans = max(sub + tmp, ans);
			}
		}
	}
	for(int i=0;i<L;i++){
		for(long long t=1;t<=min(K, L);t++){
			long long tmp = SUM[i + t] - SUM[i];
			// cout << sub + tmp << endl;
			// cout << subK << ":" << sub << ":" << tmp << endl;
			ans = max(tmp, ans);
		}
	}
	return ans;
}

int main(){
	long long N;
	long long K;
	cin >> N >> K;
	long long P[N];
	vector<long long> C;  
	for(int i=0;i<N;i++){
		cin >> P[i];
		P[i]--;
	}
	for(int i=0;i<N;i++){
		long long x;
		cin >> x;
		C.push_back(x);
	}
	vector<vector<int>> G(N);
	int D[N];
	for(int i=0;i<N;i++){
		D[i] = -1;
	}
	int num = 0;
	for(int i=0;i<N;i++){
		if(D[i] >= 0)continue;
		int tmp = i;
		while(D[tmp] < 0){
			D[tmp] = num;
			G[num].push_back(tmp);
			tmp = P[tmp];
		}
		num++;
	}
	long long SUM[num];
	for(int i=0;i<num;i++){
		// for(int j=0;j<(int)G[i].size();j++){
		// 	cout << G[i][j] << ":";
		// }
		// cout << endl;
		SUM[i] = calc(K, G[i], C);
	}
	long long ans = SUM[0];
	for(int i=1;i<num;i++){
		ans = max(ans, SUM[i]);
	}
	cout << ans << endl;
}
