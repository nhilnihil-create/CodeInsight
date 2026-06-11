#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int,int>;



int main() {
	
	
	int n; cin >> n;
	int num = 7;
	
	rep(i,n+1){
		num %= n;
		if(num == 0){
			cout << i+1 << endl;
			return 0;
		}
		num = num * 10 + 7;
	}
	cout << "-1\n"; return 0;
	return 0;
}
