#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	string s;
	cin >> s;
	int r;
	int cnt_r=0;
	int cnt_l=0;

	vector<int> ans(s.size());
	for(int i=0;i<s.size();i++){
		if(s[i]=='R') cnt_r++;
		if(s[i]=='L'){
			r = i;
			while(r<s.size()){
				r++;
				if(s[r]=='R'){
					cnt_l++;
					break;
				}
				else
					cnt_l++;
			}
		}
		if(s[i-1]=='R'&&s[i]=='L'){
			cnt_r--;
			cnt_l--;
			ans[i-1] = cnt_r/2+(cnt_l+1)/2+1;
			ans[i] = (cnt_r+1)/2+cnt_l/2+1;
			cnt_r = 0;
			cnt_l = 0;
			i = r-1;
		}
	}
	rep(i,s.size()){
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}

