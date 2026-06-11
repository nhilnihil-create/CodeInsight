#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
 
using namespace std;
using vi=vector<int>;
using pii=pair<int, int>;
using ull=unsigned long long;
using ll=long long;
 
class UFDS
{
private:
    std::vector<int> size, ps;

public:
	int groups = -1;
    UFDS(int N) : size(N + 1, 1), ps(N + 1)
    {
        // ps = {0, 1, 2, 3, ..., N}
        std::iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x) const
    {
        return x == ps[x] ? x : find_set(ps[x]);
    }

    bool same_set(int x, int y)
    {
        return find_set(x) == find_set(y);        
    }

    void union_set(int x, int y)
    {
        if (same_set(x, y))
            return;

        int p = find_set(x);
        int q = find_set(y);

        if (size[p] < size[q])
            std::swap(p, q);

        ps[q] = p;
        size[p] += size[q];
		groups = max(groups, size[p]);
    }
};
int main()
{
	int n, m; cin >> n >> m;
	UFDS dsu(n);
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		dsu.union_set(a, b);
	}
	cout << (dsu.groups == -1 ? 1 : dsu.groups) << "\n";
}
