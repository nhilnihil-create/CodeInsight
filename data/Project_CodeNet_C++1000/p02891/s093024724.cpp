#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	int k;
	std::cin >> k;
	int n = SZ(s);
	VI xd;
	int cnt = 0;
	char last = '$';
	TRAV(c, s){
		if(c == last) cnt++;
		else{
			if(cnt > 0) xd.push_back(cnt);
			cnt = 1;
			last = c;
		}
	}
	xd.push_back(cnt);
	if(SZ(xd) == 1){
		ll ile = 1ll*k*n;
		std::cout << ile/2 << "\n";
		return 0;
	}
	if(s[0] == s.back()){
		int one = 0;
		ll all = 0;
		all += xd[0]/2;
		all += xd.back()/2;
		REP(i, 1, SZ(xd)-1) one += xd[i]/2;
		all += 1ll*one*k;
		all += 1ll*(xd[0]+xd.back())/2*(k-1);
		std::cout << all << "\n";
	}else{
		int one = 0;
		TRAV(i, xd) one += i/2;
		std::cout << 1ll*one*k << "\n";
	}


	return 0;
}