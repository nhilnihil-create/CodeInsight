#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, V, P;
ll A[100010];

ll search(void){
	ll ok = N, ng = -1;
	while(ok - ng > 1){
		ll mid = (ok + ng)/2, cnt = 0, s = 0;
		for(int i=0; i<N; i++){
			if(A[i] > A[mid] + M) cnt++;
		}
		if(cnt >= P) ng = mid;
		else{
			if(V <= P) ok = mid;
			else{
				int cn = 0;
				for(int i=0; i<N; i++){
					if(cn == N-P) continue;
					if(i == mid) continue;
					s += min(A[mid] + M - A[i], M);
					cn++;
				}
				if(s >= (V-P)*M) ok = mid;
				else ng = mid;
			}
		}
	}
	return ok;
}

int main(){
	cin >> N >> M >> V >> P;
	for(int i=0; i<N; i++) cin >> A[i];
	sort(A, A+N);
	ll ans = search();
	cout << N - ans << endl;
	return 0;
}
