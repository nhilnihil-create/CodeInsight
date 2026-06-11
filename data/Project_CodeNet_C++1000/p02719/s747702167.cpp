#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	LL N, K;
	cin >> N >> K;
	LL ans = min(N % K, K - (N % K));
	cout << ans << endl;

}












