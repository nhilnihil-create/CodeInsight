#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define _READ freopen("input.txt", "r", stdin);
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<int> g(n), b(n), r(n);
    r[n - 1] = (s[n - 1] == 'R');
    g[n - 1] = (s[n - 1] == 'G');
    b[n - 1] = (s[n - 1] == 'B');
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = r[i + 1] + (s[i] == 'R');
        g[i] = g[i + 1] + (s[i] == 'G');
        b[i] = b[i + 1] + (s[i] == 'B');
    }
    // for(auto i:r)
    //     cout<<i<<" ";
    // cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(i==n-1)
                continue;
            if ((s[i] == 'R' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'R'))
            {
                ans += g[i + 1];
                if (i + (i - j) < n)
                    ans -= (s[i + (i - j)] == 'G');
            }
            if ((s[i] == 'G' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'G'))

            {
                ans += r[i + 1];
                if (i + (i - j) < n)
                    ans -= (s[i + (i - j)] == 'R');
            }
            if ((s[i] == 'R' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'R'))

            {
                ans += b[i + 1];
                if (i + (i - j) < n)
                    ans -= (s[i + (i - j)] == 'B');
                //cout<<ans<<"\n";
            }
            //cout<<ans<<"\n";
        }
    }
    cout << ans << "\n";
}
int32_t main()
{
    clock_t tStart = clock();
#ifndef ONLINE_JUDGE
    _FAST
#endif

    int t;
    t = 1;
    while (t--)
        solve();

#ifndef ONLINE_JUDGE
    cout << fixed << setprecision(5) << "\nTime taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC;
#endif

    return 0;
}
int ans = 0;

// int rbs = 0;
// int brs = 0;
// int gbs = 0;
// int bgs = 0;
// int rgs = 0;
// int grs = 0;

// map<int, int> rb;
// map<int, int> rg; //(n+1);
// map<int, int> gb; //(n+1);
// map<int, int> gr; //(n+1);
// map<int, int> br; //(n+1);
// map<int, int> bg; //(n+1);

// //rgb rbg brg bgr grb gbr
// // 2*j!=i+k
// // dp[i][r]

// for (int i = 0; i < n; i++)
// {
//     // for (int j = 0; j < i; j++)
//     // {
//     //     // if(i==n-1)
//     //     // {
//     //     //     cout<<grs<<" "<<rgs<<" "<<" "<<rg[i-j]<<"\n";
//     //     // }
//     //     if (s[i] == 'G')
//     //     {
//     //         if (br.count(i - j))
//     //             ans += brs - br[i - j];
//     //         if (rb.count(i - j))
//     //             ans += rbs - rb[i - j];
//     //     }
//     //     if (s[i] == 'R')
//     //     {
//     //         if (bg.count(i - j))
//     //             ans += bgs - bg[i - j];
//     //         if (gb.count(i - j))
//     //             ans += gbs - gb[i - j];
//     //     }
//     //     if (s[i] == 'B')
//     //     {
//     //         if (gr.count(i - j))
//     //             ans += grs - gr[i - j];
//     //         if (rg.count(i - j))
//     //             ans += rgs - rg[i - j];
//     //     }
//     // }
//     for (int j = 0; j < i; j++)
//     {
//         if (s[i] == 'G')
//         {
//             if (s[j] == 'R')
//                 rg[i - j]++, rgs++;
//             else if (s[j] == 'B')
//                 bg[i - j]++, bgs++;
//         }
//         if (s[i] == 'R')
//         {
//             if (s[j] == 'G')
//                 gr[i - j]++, grs++;
//             else if (s[j] == 'B')
//                 br[i - j]++, brs++;
//         }
//         if (s[i] == 'B')
//         {
//             if (s[j] == 'G')
//                 gb[i - j]++, gbs++;
//             else if (s[j] == 'R')
//                 rb[i - j]++, rbs++;
//         }
//     }
//     //cout<<i<<" "<<ans<<" "<<rgs<<"\n";
//     // if(rgs!=0)
//     // {
//     //     for(auto i:rg)
//     //         cout<<i.F<<" "<<i.S<<"\n";
//     // }
// }
// cout << ans;
/*
===FOR N-Dimensional Vector===
https://codeforces.com/blog/entry/76149
g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined a.cpp -o a -D_GLIBCXX_DEBUG
*/