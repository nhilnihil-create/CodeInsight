#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
using ll = long long;


template<class T>inline bool chmax(T& a, T b){if(a<b) { a=b;return true; } return false;}
template<class T>inline bool chmin(T& a, T b){if(a>b) { a=b;return true; } return false;}

int main(){
	int n;
	string s;
	cin >> n >> s;
	int a=0,b=0;
	for(int i=0;i<n;i++) if(s[i] == 'R') a++;
	int ans = max(a,b);
	for(int i=0;i<n;i++){
		if(s[i] == 'R') a--;
		else b++;
		int now = max(a,b);
		ans = min(ans,now);
	}
	cout << ans << endl;
}
