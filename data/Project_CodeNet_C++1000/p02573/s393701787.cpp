#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define vi vector<int>
#define ii pair<int, int>
#define ll long long int
#define MAX 200010
#define MOD 1000000007
#define oo 0x7fffffff
#define endl '\n'
using namespace std;

int N, M;

class UFDS{
private: vi p, size;
public:
	UFDS(int N){
		size.assign(N+1, 1);p.assign(N+1, 0);
		iota(p.begin(), p.end(), 0);
	}
	int find_set(int i) {
		return (p[i] == i) ? i : find_set(p[i]);
	}
	bool same_set(int i, int j) { 
		return find_set(i) == find_set(j);
	}
	void union_set(int i, int j) {
		if(same_set(i, j))
			return;

		int x = find_set(i), y = find_set(j);
		
		if(size[x] < size[y])
			swap(x, y);
		p[y] = x;
		size[x] += size[y];
	}
	int get_size(int i){
		return size[find_set(i)];
	}
};

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> N >> M;
	UFDS udfs(N);
	REP(i, 0, M){
		int a, b;
		cin >> a >> b;
		udfs.union_set(a, b);
	}
	int ans = 0;
	REP(i, 1, N+1){
		// cout << udfs.find_set(i) << endl;
		ans = max(ans, udfs.get_size(i));
	}
	cout << ans << endl;

    return 0;
}