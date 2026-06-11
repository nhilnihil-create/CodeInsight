//header{{{
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
#include <boost/sort/spreadsort/spreadsort.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
//#include <boost/graph/graph_utility.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
//using namespace boost::multiprecision;
//using namespace boost::math;
 
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS,
        boost::no_property, boost::property<boost::edge_weight_t, int> > Graph;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(12)
#define bsort boost::sort::spreadsort::spreadsort
#define int int_fast64_t
using pii = pair<int,int>;
 
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9+7; 
constexpr int mod2 = 998244353;
template <class Func>
 
class FixPoint : Func {
public:
    explicit constexpr FixPoint(Func&& f) noexcept : Func(forward<Func>(f)) {}
 
    template <class... Args>
    constexpr decltype(auto) operator()(Args&&... args) const {
        return Func::operator()(*this, std::forward<Args>(args)...);
    }
};
 
template <class Func>
static inline constexpr decltype(auto) makeFixPoint(Func&& f) noexcept {
    return FixPoint<Func>{forward<Func>(f)};
}
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
 
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
 
template <typename T> using Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using Umap = gp_hash_table<K, V>;
using Trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
  
inline int square(int a){ return a * a;}
inline int updiv(int a,int b){ return (a + b - 1) / b; }
 
constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};
 
struct negrightshift {
    inline int operator() (const int &x, const unsigned offset) {
        return -(x >> offset);
    }
};
//}}}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	umap<string,int> mp;
    mp.reserve(n);
	int sum = 0;
	rep(i,n){
		string s;
		cin >> s;
		bsort(all(s));
		++mp[s];
		sum += mp[s]-1;
	}
	cout << sum << '\n';
	return 0;
}
