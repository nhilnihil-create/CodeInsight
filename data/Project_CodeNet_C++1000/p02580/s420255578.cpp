#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int H, W, M;
	cin >> H >> W >> M;
	
	vi row(H,0), col(W,0);
	vpi bomb(M);
	
	for(int i=0; i<M; ++i) {
		int h, w;
		cin >> h >> w;
		--h, --w;
		bomb[i]={h,w};
		++row[h];
		++col[w];
	}
	
	int mxRow=0, mxCol=0;
	for(auto x : row) mxRow = max(mxRow, x);
	for(auto x : col) mxCol = max(mxCol, x);
	
	ll cntMxRow=0, cntMxCol=0, cntBoth=0;
	for(auto x : row) cntMxRow += (x==mxRow);
	for(auto x: col) cntMxCol += (x==mxCol);
	for(auto x : bomb) cntBoth += (row[x.f]==mxRow && col[x.s]==mxCol);
	
	if(cntMxRow*cntMxCol > cntBoth) cout << mxRow + mxCol << '\n';
	else cout << mxRow + mxCol -1 << '\n';
	
	return 0;
}
