#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define printclock cerr << "Time : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << "ms\n";
#define deb2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl
#define deb1(x) cout << #x << ": " << x << endl
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define prec(n) fixed << setprecision(n)
#define all(a) a.begin(), a.end()
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pii pair<int, int>
#define vii vector<int>
#define ld long double
#define int long long
#define MOD LLONG_MAX
#define mp make_pair
#define pb push_back
#define endl "\n";
inline void get(vector<int> &arr, int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
}
inline void print(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
/*----------------------------------TEMPLATE------------------------------------*/
/*struct UnionFind
{
    vector<int> parent;
    vector<int> size;
    UnionFind(int n)
    {
        parent = vector<int>(n,-1);
        size = vector<int>(n,1));
    }
};*/
const int mx = 2 * (1e5) + 5;
vector<int> parent(mx, -1);
vector<int> group(mx,1);
void make_set(int n)
{
    parent[n] = n;
}
int find_set(int n)
{
    if (parent[n] == n)
        return (n);
    return(parent[n] = find_set(parent[n]));
}
void union_set(int a,int b)
{
    int pa = find_set(a);
    int pb = find_set(b);
    if(pa==pb) return;
    if(group[pa]<group[pb]) swap(pa,pb);
    parent[pb] = pa;
    group[pa]+=group[pb];

}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    fast;
    /*----------------------------PEEPEEPOOPOO-------------------------------------*/
    int n,m;
    cin >> n >> m;
    rep(i,0,m)
    {
        int a,b;
        cin >> a >> b;
        if(parent[a]==-1) make_set(a);
        if(parent[b]==-1) make_set(b);
        union_set(a,b);
    }
    int ans = 0;
    rep(i,0,n+1) ans = max(ans,group[i]);
    cout << ans << endl;
    return 0;
}
/*--------------------------------PEEPEEPOOPOO-------------------------------------*/