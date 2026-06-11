//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	string s;
	cin >> s;
	s = "0" + s;
	ll carry = 0;
	string sub = "";
	for(int i = s.size()-1; i >= 1; i--){
		int num = (s[i] - '0') + carry;
		if(num < 10 - num || (num == 5 && s[i-1] <= '4')){
			carry = 0;
			ans += num;
			//sub = "o" + sub;
		}
		else{
			carry = 1;
			ans += 10 - num;
			//sub = "x" + sub;
		}
	}
	//cout << sub << endl;
	ans += carry;
	cout << ans << endl;
}