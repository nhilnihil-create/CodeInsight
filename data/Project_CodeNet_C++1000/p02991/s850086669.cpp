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
	int n, m;
	cin >>n >>m;
	vector<VI> r(n);
	rep(i, m){
		int u, v; cin >>u >>v;
		r[u-1].push_back(v-1);
	}
	int s,t; cin >>s >>t; 
	s--; t--;
	
	vector<VI> dst(n, VI(3, MD));
	queue< pair<int, int> > que;
	que.emplace(s, 0); dst[s][0]=0;
	while(!que.empty()){
		int cy,cx; tie(cy,cx) = que.front();
		que.pop();
		for(auto x: r[cy]){
			int ny=x, nx=(dst[cy][cx] + 1)%3;
			if(dst[ny][nx] == MD ){
				que.emplace(ny, nx);
				dst[ny][nx] = dst[cy][cx] + 1;
			}
		}
	}
	//for(auto xl: dst){for(auto x :xl) cerr<<x<<" ";dbg();}
	cout <<(dst[t][0] <MD? dst[t][0]/3: -1) <<"\n";
	return 0;
}
