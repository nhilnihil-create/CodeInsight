#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x;
	for(int i = 0;i < n;i++){
		int ia;
		cin >> ia;
		x.push_back(ia);
	}
	return x;
}
int main(){
	int n,k;
	cin >> n >> k;
	vector<bool> TorT(n,false);
	for(int i = 0;i < k;i++){
		int t;
		cin >> t;
		for(int i = 0;i < t;i++){
			int u;
			cin >> u;
			if(TorT[u-1] == false){
				TorT[u-1] = true;
			}
		}
	}
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(TorT[i] == false){
			cnt++;
		}
	}
	cout << cnt << endl;
}