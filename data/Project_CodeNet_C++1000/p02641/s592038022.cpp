#include <bits/stdc++.h>

using namespace std;


int main(){
	int x, n, val;
	cin >> x >> n;
	set<int> st;
	for(int i=0;i<n;++i){
		cin >> val;
		st.insert(val);
	}
	int mini = INT_MAX, ans;
	for(int i=x;i >= -1000;--i){	
		if(st.count(i) == 0){
			if(mini > abs(x - i)){
				ans = i;
				mini = abs(x - i);
				break;
			}
		}
	}
	for(int i=x;i<= 1000;++i){
		if(st.count(i) == 0){
			if(mini > abs(x - i)){
				ans = i;
				mini = abs(x - i);
				break;
			}
		}
	}
	cout << ans;
}
