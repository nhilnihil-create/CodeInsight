#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<ll,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst<<": "; dbg(rst...); }
void PR(){} template <typename T,typename ...T2> void PR(const T& fst, const T2&...rst){cout << fst; PR(rst...); }



int main()
{
	const double PI = acos(-1);
	cin.tie(0); ios_base::sync_with_stdio(false);
	int a, b;
	cin >>a >>b;
	
	if(a>b) swap(a, b);
	PR(string(b, '0'+a), "\n");
	
	return 0;
}
