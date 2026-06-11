#include <bits/stdc++.h>
using namespace std;

string s;
const int maxn = 5e5+10;
int n, countN, front[maxn];
long long ans;

int main() {
	cin >> s;
	n = s.size();

	for(int i=0; i<n; i++){
		if(s[i] == '>'){
			countN=0;
		}
		else{
			countN++;
		}
		front[i+1]=countN;
	}

	countN=0;
	for(int i=n-1; i>-1; i--){
		if(s[i] == '<'){
			countN=0;
		}
		else{
			countN++;
		}
		ans += max(countN, front[i]);
	}
	ans += front[n];
	cout << ans << endl;
}