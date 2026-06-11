#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	long long K;
	cin >> N >> K;
	int A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
		A[i]--;
	}
	int G[N];
	for(int i=0;i<N;i++){
		G[i] = 0;
	}
	G[0]++;
	int st = -1;
	long long cnt = 0;
	int now = 0;
	while(K > 0){
		now = A[now];
		K--;
		G[now]++;
		if(G[now] == 2){
			if(st == -1){
				st = now;
			}
			else{
				cnt++;
			}
		}
		else if(G[now] == 3 && now == st){
			cnt++;
			K %= cnt;
		}
		// cout << now<< ":" << K << endl;
		// cout << cnt << endl;
	}
	cout << now + 1 << endl;
}