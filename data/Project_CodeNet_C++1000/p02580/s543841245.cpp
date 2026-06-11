#include<bits/stdc++.h>
 
using namespace std;
 
#define debug(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
 
#define N 300005
int H[N], W[N];
 
int main()
{
    int h, w, m, hmx=0, wmx=0;
    cin >> h >> w >> m;
    vector<pi> p;
    for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		H[x]++;
		W[y]++;
		p.push_back({x, y});
		hmx = max(hmx, H[x]);
		wmx = max(wmx, W[y]);
	}
	lli hc=0, wc=0;
	for(int i=1; i<=h; i++) hc += (H[i] == hmx);
	for(int i=1; i<=w; i++) wc += (W[i] == wmx);
	
	lli cc = 0;
	for(auto el: p){
		if(H[el.first]==hmx && W[el.second]==wmx) cc++;
	}
	if(cc == hc*wc){
		cout << hmx+wmx-1 << endl;
	}
	else
		cout << hmx+wmx << endl;
		
 
    return 0;
}