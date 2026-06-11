// *********************************************************************************
// *                        MURTAZA MUSTAFA KHUMUSI                                *
// *                        NIT-DGP,CSE - 2019-2023                                *
// *********************************************************************************

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007;
#define loop(i, a, n) for (int i = a; i < n; i++)
#define loop1(i, b, n) for (int i = b; i <= n; i++)
#define loopit(a) for (auto it = a.begin(); it != a.end(); it++)
#define ms(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define pi pair<int, int>
#define ff first
#define ss second
#define bloop(i, a, b) for (int i = a; i > b; i--)
#define bloop1(i, a, b) for (int i = a; i >= b; i--)
#define PQ priority_queue<int> pq;
#define MPQ priority_queue<pi, vector<int>, greater<pi>> mpq;
#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);
#define se second
#define fi first

const int inf = 0x3f3f3f3f;
const int maxm = 1e6;
int sv[maxm + 1];

void sieve()
{
    ms(sv, 0);
    sv[1] = 1;

    loop1(i,1,maxm){
      sv[i]=i;
    }

    for (int i = 2; i * i <= maxm; i++)
    {
        if (sv[i]!=i)
            continue;

        for (int j = i * i; j <= maxm; j += i)
        {
            sv[j] = min(i,sv[j]);
        }
    }

    // loop1(i, 1, maxm)
    // {
    //     cout<<i<<" "<<sv[i]<<"\n";
    // }
}

set<int> factors(int num)
{
    set<int> ret;

    while (num != 1)
    {
        int sp = sv[num];
        ret.insert(sp);
        num /= sp;
    }

    return ret;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int pairw(int *arr, int n)
{
    set<int> fac;

    loop(i, 0, n)
    {
        auto it = factors(arr[i]);
        for (const auto &v : it)
        {
            if (fac.find(v) != fac.end())
            {
                return 0;
            }
            else
            {
                fac.insert(v);
            }
        }
    }
    return 1;
}

int setw(int *arr, int n)
{
    int g = arr[0];
    loop(i, 1, n)
    {
        g = gcd(arr[i], g);
    }
    return (g == 1);
}
void solve()
{

    int n;
    cin >> n;
    int a[n];
    sieve();
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    int ans1 = setw(a, n);
    int ans2 = pairw(a, n);

    if (ans2)
        cout << "pairwise coprime\n";
    else if (ans1)
        cout << "setwise coprime\n";
    else
        cout << "not coprime\n";
}

int main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    io;
    solve();

    return 0;
}
