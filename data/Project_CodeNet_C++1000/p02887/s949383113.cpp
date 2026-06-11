#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int counts = 0;
	rep(i,n){
		if(s[i] == s[i+1]) continue;
		counts++;
	}
	cout << counts << endl;
}