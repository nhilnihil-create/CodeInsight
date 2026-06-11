#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 3e5+10;
int H, W, M;
int a[MAX_N], b[MAX_N];
int row[MAX_N], col[MAX_N];

void solve()
{
	for(int i=0;i<M;++i){
		row[a[i]]++, col[b[i]]++;
	}
	const int MAXR = *max_element(row,row+H);
	const int MAXC = *max_element(col,col+W);
	// if there is a blank spot where row[i] == MAXR && col[j] == MAXC
	set<pair<int,int>> points;
	for(int i=0;i<M;++i) points.emplace(a[i],b[i]);
	vector<int> R, C;
	for(int i=0;i<H;++i)if(row[i]==MAXR)R.push_back(i);
	for(int i=0;i<W;++i)if(col[i]==MAXC)C.push_back(i);
	if((ll)R.size() * (ll)C.size() > M){
	    cout<<MAXR+MAXC;
	    return;
	}
	for(auto x : R)for(auto y : C){
		if(!points.count(make_pair(x,y))){
			cout<<MAXR+MAXC;
			return;
		}
	}
	cout<<MAXR+MAXC-1<<'\n';
}

int main()
{
	cin >> H >> W >> M;
	for(int i=0;i<M;++i){
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	solve();
	return 0;
}