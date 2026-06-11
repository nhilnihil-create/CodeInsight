#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define bug cout << "ok" << endl

const ll INF = 1e9 + 5, N = 1e6 + 5, mod = 1e9 + 7, M = 1e5 + 5;

ll d[N + 5];

ll pairwise[N + 5], a[N + 5];

int main(){
	for(int i = 2; i <= N; i++){
		if(!d[i]){
			d[i] = i;
				if(i * 1ll * i <= N){
				for(int j = i * i; j <= N; j += i){
					if(d[j] > 0) continue;
					d[j] = i;
				}
			}
		}
	}
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		int x = a[i];
		while(x > 1){
			pairwise[d[x]]++;
			int l = d[x];
			do{
				x /= l;
			} while(x % l == 0);
		}
		if(x > 1) pairwise[x]++;
	}
	bool q1 = true, q2 = true;
	for(int i = 1; i <= N; i++){
		if(pairwise[i] > 1) q1 = false;
		if(pairwise[i] == n) q2 = false;
	}
	if(q1){
		cout << "pairwise coprime" << endl;
		return 0;
	}
	if(q2){
		cout << "setwise coprime" << endl;
		return 0;
	}
	cout << "not coprime" << endl;
}