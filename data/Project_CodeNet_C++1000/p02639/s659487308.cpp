#include <bits/stdc++.h>
using namespace std;

#define len(s) int(s.size())
#define res(x) cout<<((x)?"No\n":"Yes\n")
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef long double ld;

ll mod = 1e9+7;

void solution() {
	vector<int> s(5);
	for(int& x:s){
		cin >> x;
	}
	for(int i = 0; i < len(s); ++i) {
		if(!s[i]) {
			cout << i+1;
		}
	}
	
}

int main(){
	
	int t = 1;
	//cin >> t;
	
	while(t--)
		solution();
	
	return 0;
}
