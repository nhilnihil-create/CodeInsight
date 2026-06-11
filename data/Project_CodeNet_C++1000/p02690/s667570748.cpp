#include <bits/stdc++.h>


#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

const int N = 2e5 + 10;


using namespace std;




int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    IOS;

    ll x;

    cin >> x;

    for (ll i = -2000; i <= 2000; i++)
    {
        for (ll j = -2000; j <= 2000; j++)
        {
            if (i * i * i * i * i - j * j * j * j * j == x)
            {
                cout << i << " " << j;

                return 0;
            }
        }
    }
}