#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
int main()
{
	string s;
	cin >> s;
	int nextL=0,lastR=0;
    vector<int> ans(s.size());
	rep(i,s.size()){
		while(s[nextL] != 'L' || nextL < i){
			nextL++;
		}
		if(s[i] == 'R'){
			lastR = i;
			if((nextL-i)%2 == 0){
				ans[nextL]++;
			}else{
				ans[nextL-1]++;
			}
		}else{
			if((i-lastR)%2 == 0){
				ans[lastR]++;
			}else{
				ans[lastR+1]++;
			}
		}
	}
	rep(i,s.size()){
		cout << ans[i] << ' ';
	}
	return 0;
}