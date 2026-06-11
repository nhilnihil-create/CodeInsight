#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];

	int next_num = 1, idx = 0, cnt = 0;
	while(idx < n){
		if(a[idx] == next_num){
			next_num++;
		}else{
			cnt++;
		}
		idx++;
	}

	if(cnt == n) cout << -1 << endl;
	else cout << cnt << endl;
	return 0;
}