#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	rep(i,n) cin >> h.at(i);
	vector<bool> flg(n,true);
	
	rep(i,m){
		int a,b;
		cin >> a >> b;
		if(h[a-1] > h[b-1]) flg[b-1] = false;
		else if(h[a-1] < h[b-1]) flg[a-1] = false;
		else flg[a-1] = flg[b-1] = false;
	}
	
	int ans = 0;
	rep(i,n){
		if(flg[i]) ans++;
	}
	cout << ans << endl;
	
}