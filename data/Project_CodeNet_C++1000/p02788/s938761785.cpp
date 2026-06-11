#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

#include <chrono>

#define INF 1e9
#define LL_INF 1e18

#define nmax 200010

#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)(x.size()))

#define MOD 1000000007
#define MOD1 998244353
#define MOD2 666013
#define P1 255
#define P2 2059

using namespace std;

typedef long long int ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int n, d, a;
ll sum[nmax];
pii h[nmax];

int find_hgh(int l, int r, ll val)
{
    int sol = l;

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (h[m].fst <= val) { sol = m; l = m + 1; }
        else
            r = m - 1;
    }

    return sol;
}

int main()
{
    scanf("%d %d %d", &n, &d, &a);

    for (int i = 1; i <= n; i++) {

        scanf("%d %d", &h[i].fst, &h[i].snd);

        h[i].snd = (h[i].snd / a) + (h[i].snd % a > 0);
    }

    sort(h + 1, h + n + 1);

    ll answer = 0;
    ll cur_sum = 0;

    for (int i = 1; i <= n; i++) {

        ll cent = h[i].fst + d;
        int r = find_hgh(i, n, cent + d);

        cur_sum += sum[i];

        ll val = max(0LL, h[i].snd - cur_sum);

        if (val > 0) {

            answer += val;
            cur_sum += val;

            sum[r + 1] -= val;
        }
    }

    printf("%lld", answer);

    // IMPORTANT!!!!!
    // Are you missing something????
    // check limits, int or ll

    return 0;
}