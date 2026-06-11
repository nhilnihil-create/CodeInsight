#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	string s;
	int k;
	cin >> s >> k;
	int cnt=0;
	rep(i,s.size()-1){
		if(s[i]==s[i+1])
			cnt++;
	}
	//全ての文字が同じの時だけ例外
	if(cnt==s.size()-1){
		cout << s.size()*k/2 <<endl;
		return 0;
	}
	string three = s+s+s;
	string two = s+s;
	ll n1 = 0;
	rep(i,three.size()-1){
		if(three[i]==three[i+1]) {
			n1++;
			i++;
		}
	}
	ll n2 = 0;
	rep(i,two.size()-1){
		if(two[i]==two[i+1]) {
			n2++;
			i++;
		}
	}
	ll ans = n2+(k-2)*(n1-n2);
	cout << ans << endl;
		return 0;
}
