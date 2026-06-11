#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 16;
int N;
int A[MAX_N][MAX_N][2];
int cur[MAX_N];

void solve()
{
	int ans = 0;
	for(int f=0;f<(1<<N);++f){
		memset(cur,-1,sizeof(cur));
		bool ok = true;
		for(int i=0;i<N;++i)if(f>>i&1){
			for(int j=1;j<=A[i][0][0];++j){
				if(A[i][j][1]){
				    if(!(f>>(A[i][j][0]-1)&1)){
				        ok=false;
				        goto out;
				    }
					if(cur[A[i][j][0]] == 0){
						ok=false;
						goto out;
					}
					cur[A[i][j][0]] = 1;
				}else{
					if(f>>(A[i][j][0]-1)&1){
						ok=false;
						goto out;
					}
				}
			}
		}
		out:
		if(ok){
			ans=max(ans, __builtin_popcount(f));
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i){
		cin >> A[i][0][0];
		for(int j=1;j<=A[i][0][0];++j){
			cin >> A[i][j][0] >> A[i][j][1];
		}
	}
	solve();
	return 0;
}