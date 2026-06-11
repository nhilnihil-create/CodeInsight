#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int sq[n];
	for(int i = 0; i < n; i++){
		cin >> sq[i];
	}
	map<int, int>ms;
	for(int i = 0; i < n; i++){
		ms[i + 1] = sq[i];
	}
	int cnt = 0;
	for(auto x : ms){
		if(x.first%2 != 0 && x.second%2 != 0){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}