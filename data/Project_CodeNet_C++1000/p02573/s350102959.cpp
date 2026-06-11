#include <bits/stdc++.h>
 
using namespace std;

// traduções

// even -> par
// odd -> impar
// west -> oeste

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-12
const double PI = acos(-1.0);

#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define FILL(a,v) memset(a, v, sizeof a)

// bitmask operations
#define SETBIT(S, j) S |= (1 << j)
#define CLEARBIT(S, j) S &= ~(1 << j)
#define ISSET(S, j) S & (1 << j)
#define FLIPBIT(S, j) S ^= (1 << j)
#define LSBIT(S) (S & (-S))

// debug
#define DEBUGSTR(S) cout << "(" << S << ")\n";

int tranform(int i, int j, int M) {
    return j + M*i;
}

class UFDS {
private:
    vi size, ps;
    int numSets;

public:
    UFDS(int N) : size(N + 1, 1), ps(N + 1), numSets(N) {
        iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x) {
        return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
    }

    bool same_set(int x, int y) {
        return find_set(x) == find_set(y);
    }

    int getMax() {
        int maior = -1;
        int sz = size.size();
        for(int i = 0; i < sz; ++i)
            maior = max(maior, sizeOfSet(i));
        
        return maior;
    }

    int sizeOfSet(int i) { return size[find_set(i)]; }

    int numDisjointSets() const { return numSets; }

    void union_set(int x, int y) {
        int p = find_set(x), q = find_set(y);

        if(p == q)
            return;
        
        numSets--;

        if (size[p] < size[q])
            swap(p, q);

        ps[q] = p;

        size[p] += size[q];
    }
};

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    scanf(" %d %d", &N, &M);

    UFDS UF(N);

    REP(i, 0, M) {
        int a, b;
        scanf(" %d %d", &a, &b);

        UF.union_set(a, b);
    }

    printf("%d\n", UF.getMax());

    return 0;
}
