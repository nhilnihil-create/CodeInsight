#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];
	bool ok = false;
	int tmp = 1;
	rep(i,N){
		if(a[i] == tmp) {
			tmp++;
			ok = true;
		}
	}
	if(ok)	cout << N - tmp + 1 << endl;
	else cout << -1 << endl;
}











