#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 1000050;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
int n;
int s[N];
multiset<int, greater<int>> S1, S2;
set<int> vis;
int id[N];
int tot;

inline int Query(int x)
{
    auto it = vis.lower_bound(x);
    if (it != vis.begin())
    {
        it--;
        return *it;
    }
    return -1;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= st(n); ++i)
        scanf("%d", &s[i]);
    for (int i = 1; i <= st(n); ++i)
        vis.insert(s[i]);
    for (int i = 1; i <= st(n); ++i)
        S1.insert(s[i]);
    sort(s + 1, s + st(n) + 1, greater<int>());
    S2.insert(s[1]);
    S1.erase(S1.find(s[1]));
    if (S1.count(s[1]) == 0)
        vis.erase(s[1]);
    int tim = 1;
    vector<int> tmp;
    while (tim <= n)
    {
        // puts("flag");
        tmp.clear();
        for (auto &i : S2)
        {
            int x = Query(i);
            if (S1.empty())
                return puts("Yes"), void();
            if (x == -1 || S1.find(x) == S1.end())
                return puts("No"), void();
            S1.erase(S1.find(x));
            if (S1.find(x) == S1.end())
                vis.erase(x);
            if (S1.empty())
                return puts("Yes"), void();
            tmp.push_back(x);
        }
        for (auto &i : tmp)
            S2.insert(i);
        tim++;
    }
    puts("No");
}

int main()
{
    TIME_START = clock();
    int Test = 1;
    // cin >> Test;
    while (Test--)
        solve();
    TIME_END = clock();
    program_end();
    return 0;
}
/*
3
5 4 4 4 3 3 2 1
*/