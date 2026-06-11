#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	int h[N];
	int ans = 0;
	for(int i=0;i<N;i++){
		cin >> h[i];
		if(h[i] >= K)ans++;
	}
	cout << ans << endl;
}