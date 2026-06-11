#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//large-debug
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A,B>& p){os << "{" << p.first << "," << p.second << "}";return os; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "{"; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << "}"; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; for(int i = 0;i < (int)v.size(); i++) o << v[i] << (i != (int)v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const set<T,U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const multiset<T,U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << "["; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it)!=m.end()?", ":"]");  return o; }
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; cerr << "[";while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << (tmp.size()?", ":"]");} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; cerr <<"[";while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << (tmp.size()?", ":"]");} return o; }
template<class T> inline ostream& operator<<(ostream& os,vector<T> arr) {os << "["; for(int i = 0; i < (int)arr.size(); i++)os << arr[i] << (i == (int)arr.size() - 1 ? "]" : ", ");os << endl;return os;}
void prstr(string s, char c){for(int i = 0; i < (int)s.size(); i++)cerr << (char)(s[i] + c) << (i+1 == (int)s.size() ? "\n" :"");}
#define prvec(v) cerr<<#v<<": [";for(int __i = 0;__i < (int)(v).size(); __i++)cerr<<((v)[__i])<<(__i+1==(int)(v).size()?"]\n":",");
#define print(x) cerr<<#x<<": "<<(x)<<endl
//<pair>/<tuple>/<deque>/<set>/<multiset>/<map>/<unordered_map>/<priority_queue>/<queue>/



class Osa_k {
private:
	int n;
	vector<int> factor;

	void dfs(int val, int idx ,vector<int>& ans, map<int,int>& mp,const vector<int> &facts) {
		if(idx == (int)facts.size()) {
			ans.push_back(val);
			return;
		}
		int v = facts[idx];
		for(int i = 0; i <= mp[v]; i++) {
			dfs(val, idx+1, ans, mp, facts);
			val *= v;
		}
	}


public:

	//O(NloglogN)
	Osa_k(int _n):n(_n) {
		factor.assign(n, 0);
		iota(factor.begin(), factor.end(), 0);
		for(int i = 2; i*i < n; i++) {
			if(factor[i] < i)continue;
			for(int j = i * i; j < n; j += i) {
				if(factor[j] == j)factor[j] = i;
			}
		}
	}

	//O(logV)
	map<int, int> sieve(int v) {
		map<int, int> ret;
		while(v != factor[v]) {
			ret[factor[v]]++;
			v /= factor[v];
		}
		if(v != 1)ret[v]++;
		return ret;
	}


	vector<int> divisor(int v) {
		map<int,int> mp = sieve(v);
		vector<int> factors;
		for(auto i : mp)factors.emplace_back(i.first);
		vector<int> ans;
		dfs(1, 0, ans, mp, factors);
		sort(ans.begin(), ans.end());
		return ans;
	}


	//O(N)
	vector<int> get_list() {
		vector<int> prime;
		for(int i = 2; i < n; i++)if(factor[i] == i)prime.emplace_back(i);
		return prime;
	}

	//O(1)
	bool is_prime(int v) {
		if(v <= 1)return false;
		return (factor[v] == v);
	}

}fact(1000001);



int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        vector<int> s = fact.divisor(a[i]);
        int m = s.size();
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            cnt += upper_bound(a.begin(), a.end(), s[j]) - lower_bound(a.begin(), a.end(), s[j]); 
        }
        if(cnt == 1)ans++;
    }
    cout << ans << endl;
}