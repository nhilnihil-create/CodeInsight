#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define nout(ans) cout << (ans) << "\n"
#define sout(ans) cout << (ans) << " "
using namespace std;

const double pi = 3.14159265359;
const ll INF = 1e12;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;
/*
Decimal Places: cout << fixed << setprecision(n) << ans << endl

String to integer:
stringstream dark(s);
int x = 0; dark >> x;
*/

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}


int n; float a[102];

void solve()
{
    cin >> n;
    float s = 0;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) s+=1/a[i];
    cout << fixed << setprecision(10) << 1/s << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++)
    {
        solve();
    }
    return 0;
}