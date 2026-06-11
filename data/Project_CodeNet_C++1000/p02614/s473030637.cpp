#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

int h, w, k;

int black(vector<string>& a)
{
    int c = 0;
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
        c += (a[i][j] == '#');
    return c;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w >> k;
    vector<string> a(h);
    for(int i=0;i<h;i++)
        cin >> a[i];
    
    int ans = 0;
    int r=pow(2,h), c=pow(2,w);
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        vector<string> v = a;
        bitset<6> a(i), b(j);
        for(int p=0;p<6;p++)
            if( a[p] )
            for(int q=0;q<w;q++)
                v[p][q] = 'R';
        for(int p=0;p<6;p++)
            if( b[p] )
            for(int q=0;q<h;q++)
                v[q][p] = 'R';
        ans += (black(v)==k);
    }
    cout << ans;
}