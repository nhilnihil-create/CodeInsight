#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	stack<int> st;
	int p = n;
	while(p != 0){
		bool flag = false;
		for(int i = m; i > 0; i--){
			if(p-i < 0) continue;
			if(s[p-i] == '0'){
				flag ^= true;
				st.push(i);
				p -= i;
				break;
			}
		}
		if(flag == false){
			cout << -1 << endl;
			return 0;
		}
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return 0;
}