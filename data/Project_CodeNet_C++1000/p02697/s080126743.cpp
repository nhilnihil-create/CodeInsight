#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	
	int hm = m /2;
	int amx = hm + m%2;
	rep(i, amx){
		printf("%d %d\n", i+1, i+ 2*(amx-i));
	}
	int zs = 2*amx +1;
	rep(i, hm){
		printf("%d %d\n",zs+i, zs+i+ 2*(hm-i));
	}
	return 0;
}
