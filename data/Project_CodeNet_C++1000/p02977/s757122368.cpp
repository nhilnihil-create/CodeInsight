#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n;

bool checkPow2(int k)
{
    // cerr<<k<<"\n";
    for (int i=0; i<=20; i++) if (k==(1<<i)) return 1;
    return 0;
}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if (n==1) cout<<"No";
    else if (n%2==0)
    {
        if (checkPow2(n)) cout<<"No";
        else
        {
            vector <pii> V={{2, 1}, {1, 3}, {3, n+2}, {n+2, n+1}, {n+1, n+3}};
            int temp=0;
            while ((1<<(temp+1))<n) 
            {
                temp++;
                // cerr<<temp<<"\n";
            }

            int t2=(1<<temp);
            V.push_back({1, t2});
            V.push_back({3, t2+1});
            V.push_back({t2+1, t2+2});
            V.push_back({3, n+t2+2});
            V.push_back({n+t2, n+t2+2});
            V.push_back({n+t2+1, n+t2+2});

            for (int i=4; i<t2; i+=2)
            {
                V.push_back({i, i+1});
                V.push_back({i+1, 1});
                V.push_back({1, i+n});
                V.push_back({i+n, i+n+1});
            }

            for (int i=t2+3; i<n; i+=2)
            {
                V.push_back({i, i+1});
                V.push_back({i+1, i^(i+1)});
                V.push_back({i^(i+1), i+n});
                V.push_back({i+n, i+n+1});
            }

            cout<<"Yes\n";
            for (pii P: V) cout<<P.XX<<" "<<P.YY<<"\n";
        }
        
    }
    else
    {
        vector <pii> V={{1, 2}, {2, 3}, {3, n+1}, {n+1, n+2}, {n+2, n+3}};
        for (int i=4; i<n; i+=2) 
        {
            V.push_back({i, i+1});
            V.push_back({i+1, 1});
            V.push_back({1, n+i});
            V.push_back({n+i, n+i+1});
        }
        cout<<"Yes\n";

        for (pii P: V) cout<<P.XX<<" "<<P.YY<<"\n";
        

    }
    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/