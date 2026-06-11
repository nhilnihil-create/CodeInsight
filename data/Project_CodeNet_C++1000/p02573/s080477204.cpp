#include <bits/stdc++.h>
#define load ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
#define ll long long
#define ull unsigned long long
#define fori(i,n) for (int i=0; i<int(n);i++)
#define srt(v) sort(v.begin(), v.end())
#define MOD 1000000007
const int INF = 1e9;
const double PI = 3.14159265358979323846;
ll gcd(ll a, ll b) {
    return b != 0 ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
ll spow(ll base, ll exp){
	ll ans = 1;
	for(ll i=0;i<exp;i++) ans = ans * base % MOD;
	return ans;
}
ll divide(ll a, ll b){
	return a * spow(b, MOD-2) % MOD;
}
void solve(){
	
}

struct UnionFind {
	vector<int> parent;
	
	UnionFind(int N){
		parent = vector<int> (N, -1);
	}
	int root(int x){
		if (parent[x] < 0) return x;
		return parent[x] = root(parent[x]);
	}
	bool unite(int x, int y){
		int parentA = root(x);
		int parentB = root(y);
		if (parentA == parentB) return false;
		if (parent[parentA] > parent[parentB]) swap(parentA, parentB);
		
		parent[parentA] += parent[parentB];
		parent[parentB] = parentA;
		return true;
		
	}
	int size(int x){
		return -parent[root(x)];
	}
};

int main(){
	//~ load;
	//~ int t;
	//~ cin >> t;
	//~ while(t--){
		//~ solve();
	//~ }
	
	int N, M;
	cin >> N >> M;
	UnionFind uf(N);
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		uf.unite(a, b); // 其实这里是把有关系的号码放在同一组
	}
	int res = 0;
	for(int i=0; i<N; i++){
		res = max(res,  uf.size(i)); // 我们看那个最大的组有多少个号码，我们就可以知道我们要分割成多少组， 因为组跟组之间是没有人和关系的
	}
	cout << res << "\n";
}

