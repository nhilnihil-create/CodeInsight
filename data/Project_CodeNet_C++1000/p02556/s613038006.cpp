#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std;

#define int           long long 
#define S             second
#define F             first
#define pb            push_back
#define all(c)        (c).begin(),(c).end()
#define rall(c)       (c).rbegin(),(c).rend() 
#define lb            lower_bound
#define ub            upper_bound
#define si(c)         (int)((c).size())
#define lcm(a, b)      (a * (b / __gcd(a,b)))  
#define inf           (int)(4e18)
// #define endl          '\n'
#define mp            make_pair
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define debug(args...)    _F(#args, args)
#define vi            std::vector<int>
#define pii           pair<int, int> 
#define vpi           vector<pii>
#define ordered_set   tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

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


void solve() {
	int n; cin >> n;
	vpi v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(all(v));

	int mx1 = -v[0].F-v[0].S;
	int mx2 = -v[0].F+v[0].S;
	int ans = 0;
	for(int i = 1; i < n; i++) {
		ans = max(ans, v[i].F+v[i].S+mx1);
		ans = max(ans, v[i].F-v[i].S+mx2);
		mx1 = max(mx1, -v[i].F-v[i].S);
		mx2 = max(mx2, -v[i].F+v[i].S);
	}
	cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);   
    start = clock(); 

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int test = 1;
    // cin >> test;
    
    cout << fixed << setprecision(2);
     
    for(int i = 1; i <= test; ++i){
    	solve();
    }

    cerr << time(start);
    return 0;
}
