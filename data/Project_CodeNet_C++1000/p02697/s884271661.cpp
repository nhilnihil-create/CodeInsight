#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long

#define for(i,a,b) for (i=a; i<b; i++)
#define forb(i,a,b) for (i=a; i>b; i--)
#define all(S) S.begin(),S.end()
#define sort(S) sort(all(S))

const int inf = 1e9+7;
const ll INF = 1e18;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,i;
    cin >> n >> m;
    int l = 1;
    int r = n;
    for (i,0,m)
    {
        if (r-l==n/2 && n%2==0)
            r--;
        if (l+l-2==n/2 && n%2==0)
            r--;
        cout << l << " " << r << endl;
        l++;
        r--;
    }
    return 0;
}
