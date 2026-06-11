#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >

using namespace std;

typedef long long lint;

void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

const lint MOD = 1000000007LL;
lint K2[100010];
lint F[100010];

lint mod_exp(lint a, int x)
{
    if (x == 0)
        return 1LL;
    if (x % 2 == 1)
        return mod_exp(a, x - 1) * a % MOD;
    lint ret = mod_exp(a, x / 2);
    return ret * ret % MOD;
};

lint f(int v, vector<vector<int> >& edges, int par, int K)
{
    int children = 0;
    lint prod = 1;
    for (int c : edges[v])
        if (c != par) {
            prod = prod * f(c, edges, v, K) % MOD;
            children++;
        }

    prod = K2[children] * prod % MOD;
    return F[children] * prod % MOD;
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, K;
    cin >> N >> K;

    lint t = 1;
    for (int i = 0;i < K - 1;i++) {
        K2[i] = t;
        t = t * (K - 2 - i) % MOD;
        t = t * mod_exp(i + 1, MOD - 2) % MOD;
    }

    F[0] = 1LL;
    for (int i = 1;i <= K;i++)
        F[i] = F[i - 1] * i % MOD;

    vector<vector<int> > edges(N);
    for (int i = 0;i < N - 1;i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // K * (K - 1 choose children of root)
    int rootc = edges[0].size();
    lint ret = rootc == 0 ? 1 : 
                    (rootc > K - 1 ? 0 : (K2[rootc - 1] + K2[rootc]) % MOD);
    ret = K * 1LL * ret % MOD;
    ret = ret * F[rootc] % MOD;
    for (int c : edges[0])
        ret = ret * f(c, edges, 0, K) % MOD;
    cout << ret << endl;
    return 0;
};
