#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	vector<LL> H(N);
	rep(i,N) cin >> H[i];
	int ans = 0;
	int tmp = 0;
	rep(i,N-1){
		if(H[i] >= H[i+1]) tmp++;
		else {
			
			tmp = 0;
		}ans = max(ans, tmp);
	}
	cout << ans << endl;
		

}












