#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+100;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> upVals(n);
	vector<int> downVals(n);
	for (int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		upVals[i] = y-x;
		downVals[i] = y+x;
	}
	sort(upVals.begin(), upVals.end());
	sort(downVals.begin(), downVals.end());
	cout<<max(upVals[n-1]-upVals[0], downVals[n-1]-downVals[0])<<'\n';
	return 0;
}