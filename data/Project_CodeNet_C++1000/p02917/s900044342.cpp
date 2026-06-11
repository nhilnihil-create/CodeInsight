#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const int INF=1e9;

int main(){
	int N;
	cin >> N;
	vector<int> B(N+1);
	rep(i,N-1) cin >> B[i+1];
	B[0]=INF, B[N]=INF;
	int ans=0;
	rep(i,N) ans+=min(B[i],B[i+1]);
	cout << ans << endl;

	return 0;
}