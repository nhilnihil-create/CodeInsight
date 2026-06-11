#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

// [a -> b-1]
#define reps(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
// [0 -> a-1]
#define rep(i, a) reps(i, 0, (a))
// [a-1 -> b]
#define rreps(i, a, b) for (int i = (int)((a)-1); i >= (int)(b); i--)
// [a-1 -> 0]
#define rrep(i, a) rreps(i, a, 0)
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
 * (v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)\
	sort(all(v));\
	(v).erase(unique(all(v)), v.end())
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmax(a, b) a = max(a, (b))
#define fcout cout << fixed << setprecision(15)
#define YES(f) cout << ((f) ? YES_STR : NO_STR) << endl;

#ifdef LOCAL_DEBUG_OPTION
namespace debug_print_n{
struct DebugPrint {
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_integral<U>::value && !is_same<U, bool>::value && !is_same<U, char>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << x;
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, bool>::value> DUMP_SUB_FUNCTION(T x) {
		if (x) cerr << "True";
		else cerr << "False";
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, char>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << '\'' << x << '\'';
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, string>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << '\"' << x << '\"';
	}
	template<class T>
	static enable_if_t<is_same<T, const char*>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << string(x);
	}
	template<class T>
	static enable_if_t<true> DUMP_SUB_FUNCTION(vector<T> x) {
		cerr << '{';
		for (size_t i = 0; i < x.size(); i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(x[i]);
		}
		cerr << '}';
	}
	template<class T, size_t N>
	static enable_if_t<true> DUMP_SUB_FUNCTION(array<T, N> x) {
		cerr << '{';
		for (size_t i = 0; i < x.size(); i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(x[i]);
		}
		cerr << '}';
	}
	template<class T>
	static enable_if_t<true> DUMP_SUB_FUNCTION(set<T> x) {
		cerr << '[';
		size_t i = 0;
		for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(*itr);
		}
		cerr << ']';
	}
	template<class T, class U>
	static enable_if_t<true> DUMP_SUB_FUNCTION(map<T, U> x) {
		cerr << '[';
		size_t i = 0;
		for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(itr->first);
			cerr << " : ";
			DUMP_SUB_FUNCTION(itr->second);
		}
		cerr << ']';
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_floating_point<U>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << fixed << setprecision(5) << x;
	}
	template<class T, class U>
	static enable_if_t<true> DUMP_SUB_FUNCTION(pair<T, U> p) {
		cerr << '(';
		DUMP_SUB_FUNCTION(p.first);
		cerr << ", ";
		DUMP_SUB_FUNCTION(p.second);
		cerr << ')';
	}
	template<int num = 0, class... Args>
	static enable_if_t<num == sizeof...(Args)> DUMP_SUB_FUNCTION(tuple<Args...> t) {
		if (num) cerr << ')';
	}
	template<int num = 0, class... Args>
	static enable_if_t<num < sizeof...(Args)> DUMP_SUB_FUNCTION(tuple<Args...> t) {
		if (num == 0) cerr << '(';
		DUMP_SUB_FUNCTION(get<num>(t));
		if (num + 1 < sizeof...(Args)) cerr << ", ";
		DUMP_SUB_FUNCTION<num+1>(t);
	}
	template<long unsigned N>
	static enable_if_t<true> DUMP_SUB_FUNCTION(bitset<N> x) {
		cerr << x;
	}
};
void dump() {
	cerr << endl;
}
template<class Head, class... Tail>
void dump(Head&& head, Tail&&... tail) {
	DebugPrint::DUMP_SUB_FUNCTION(head);
	if (sizeof...(Tail) != 0) {
		cerr << ' ';
	}
	dump(forward<Tail>(tail)...);
}
} // namespace debug_print_n
using debug_print_n::dump;
#else
template<class... Args> void dump(Args&&... args) { }
#endif

namespace bit {
using u32 = uint_fast32_t;
using u64 = unsigned long long;
template<class T>
constexpr T set(T bin, u32 pos) {
	return bin | (1ull << pos);
}
template<class T>
constexpr T unset(T bin, u32 pos) {
	return bin & ~(1ull << pos);
}
template<class T>
constexpr T get(T bin, u32 pos) {
	return bin & (1ull << pos);
}
template<class T>
constexpr bool check(T bin, u32 pos) {
	return get(bin, pos);
}
constexpr u32 popcount(u64 bin) {
	return __builtin_popcountll(bin);
}
} // namespace bit

// const string YES_STR = "Yes";
// const string NO_STR = "No";

namespace RmQ_n {
/**
 * @title セグメント木
 * @brief 0-indexed 半開区間
 * @brief クラス Node は Monoid であり、{型(monoid_type), 演算(operator+), 単位元(default constructor), constructor(monoid_type)} の4つを持つ。
 * @brief Node の具体例は monoid/ にある。
 */
namespace segmenttree_n {
template<class Node>
struct SegmentTree {
	using node_type = typename Node::monoid_type;
	using index_type = uint_fast32_t;
	index_type n;
	vector<Node> node;
	// @brief サイズ N で初期化(初期値は単位元) O(N)$
	SegmentTree (index_type N) {build(N);}
	// @brief vector で初期化 O(N)$
	SegmentTree (const vector<node_type>& v) {build(v);}
	// @brief サイズ N で再構築(初期値は単位元) O(N)$
	void build(index_type N) {
		n = calc_n(N);
		node.clear(); node.resize(2*n-1);
	}
	// @brief vector で再構築 O(N)$
	void build(const vector<node_type>& v) {
		build(index_type(v.size()));
		for (size_t i = 0; i < v.size(); i++) {
			node[i+n-1].val = v[i];
		}
		for (int i = n - 2; i >= 0; i--){
			node[i] = Node::merge(node[i*2+1], node[i*2+2]);
		}
	}
	// @brief index i に v を代入 O(\log N)$
	void set(index_type i, Node v) {
		i += n - 1;
		node[i] = v;
		while (i) {
			i = (i-1) / 2;
			node[i] = Node::merge(node[i*2+1], node[i*2+2]);
		}
	}
	// @brief [l, r) を取得 O(\log N)$
	node_type get(index_type l, index_type r) const {
		Node val_l, val_r;
		for (l += n-1, r += n-1; l < r; l /= 2, r = (r - 1) / 2) {
			if (l % 2 == 0) val_l = Node::merge(val_l, node[l]);
			if (r % 2 == 0) val_r = Node::merge(node[r-1], val_r);
		}
		return Node::merge(val_l, val_r).val;
	}
	// @brief index i を取得 O(\log N)$
	const node_type& operator[](index_type i) const {
		return node[i+n-1].val;
	}
private:
	index_type calc_n(index_type n_, index_type t = 1) {return n_ > t ? calc_n(n_, t << 1) : t;}
};
} // namespace segmenttree_n
using segmenttree_n::SegmentTree;
namespace min_monoid_n {
template<class T>
struct min_monoid {
	using monoid_type = T;
	T val;
	min_monoid(T v) : val(v) {}
	min_monoid() : val(numeric_limits<T>::max()) {}
	static min_monoid merge(const min_monoid& lhs, const min_monoid& rhs) {
		return min_monoid(min(lhs.val, rhs.val));
	}
};
}
using min_monoid_n::min_monoid;
template<class T> using RmQ = SegmentTree<min_monoid<T>>;
}
using RmQ_n::RmQ;

signed main(){
	int N, M; cin >> N >> M;
	vector<int> v(N+1);
	{
		string s;
		cin >> s;
		reverse(all(s));
		rep(i, N+1) v[i] = s[i] == '0';
	}
	{
		int l = 0;
		rep(i, N+1) {
			if (!v[i]) {
				l++;
				if (l == M) {
					cout << -1 << endl;
					return 0;
				}
			} else {
				l = 0;
			}
		}
	}
	RmQ<int> rmq(N+1);
	rmq.set(0, 0);
	reps(i, 1, N+1) {
		if (!v[i]) continue;
		rmq.set(i, rmq.get(max(0ll, i - M), i) + 1);
	}
	vector<int> m(rmq[N]+1);
	rep(i, N+1) {
		if (rmq[i] == LLONG_MAX) continue;
		m[rmq[i]] = i;
	}

	rrep(i, rmq[N]) {
		cout << m[i+1] - m[i] << " \n"[i==0];
	}
}
