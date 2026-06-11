#include <bits/stdc++.h>
using namespace std;

#define int           long long 
#define S             second
#define F             first
#define pb            push_back
#define all(c)        (c).begin(),(c).end()
#define rall(c)       (c).rbegin(),(c).rend() 
#define lb            lower_bound
#define si(c)         (int)((c).size())
#define lcm(a, b)      (a * (b / __gcd(a,b)))  
#define inf           (int)(1e18)
#define endl          '\n'
#define mp            make_pair
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define debug(args...)    _F(#args, args)
#define vi            std::vector<int>
#define pii           pair<int, int> 
#define vpi           vector<pii>

clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

template<typename T> void _F(const char *name, T arg1){ cerr << name << " = " << arg1 << endl;}
template<typename T, typename... Args> void _F(const char *names, T arg1, Args... args)
{ const char *name = strchr(names, ',');cerr.write(names, name-names) << " = " << arg1 << endl;_F(name+2, args...);}

template< typename T1, typename T2 > istream& operator>>(istream& in, pair<T1, T2> &q){ in >> q.F >> q.S; return in;}
template< typename T1, typename T2 > ostream& operator<<(ostream& out, pair<T1, T2> &q){ out << q.F << " " << q.S; return out;}
template< typename T1, typename T2 > pair<T1, T2> operator+(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F+p2.F, p1.S+p2.S};}
template< typename T1, typename T2 > pair<T1, T2> operator-(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F-p2.F, p1.S-p2.S};}
template< typename T1, typename T2 > bool operator<(pair<T1, T2> p1, pair<T1, T2> p2){ return p1 < p2 ;}

template<typename T> void Unique(vector<T> &v){
    sort(all(v)), v.resize(distance(v.begin(), unique(all(v))));
}

void solve(int &test) {
	int h, w, m;
	cin >> h >> w >> m;

	int row[h+1], col[w+1];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));

	vi r[h+1];

	for(int i = 0; i < m; i++) {
		int hh, ww;
		cin >> hh >> ww;
		row[hh]++, col[ww]++;

		r[hh].pb(ww);
	}

	set<pair<int, int> > s;
	for(int i = 1; i <= w; i++)
		s.insert(mp(col[i], i));
	int ans = 0;

	for(int i = 1; i <= h; i++) {
		for(auto u : r[i]) {
			ans = max(ans, col[u]+row[i]-1);
			s.erase(mp(col[u], u));
		}
		if(si(s))ans = max(ans, row[i]+(*rbegin(s)).F);
		for(auto u : r[i]) {
			s.insert(mp(col[u], u));
		}
	}

	cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);   
    start = clock(); 

   
    int t = 1;
    // cin >> t;

    cout << fixed << setprecision(2);
     
    for(int i = 1; i <= t; ++i){
        solve(i); 
    }

    cerr << time(start);
    return 0;
}