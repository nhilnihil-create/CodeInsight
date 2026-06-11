#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n % 2 != 0){
		cout << "No" << endl;
		return 0;
	}
	rep(i, n/2){
		if(s[i] != s[n/2+i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
    return 0;
}