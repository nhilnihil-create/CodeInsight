#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long double PI = acos(-1);
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fo(i,n) for(int i=0;i<(int)n;i++)
#define fo1(i,n) for(int i=1;i<=(int)n;i++)
#define deb(x) cout<<#x<<"="<<x<<endl

void solve(int tc)
{
    int x, y, d, c = 0;
    cin >> x >> y >> d;
    for(; x <= y; x++) if(x % d == 0)c++;
    cout << c << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    fo1(t, tc)
    {
        solve(t);
    }
    return 0;
}