#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;cin >> n;
    vector<int> a(n);
    vector<P> ta(n);
    vector<int> b(n);
    vector<P> tb(n);
    rep(i,n){
        cin>> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int am,bm;
    int ans;
    if(n%2==0)
    {
        am = a[n / 2 - 1] + a[n / 2];
        bm = b[n / 2 - 1] + b[n / 2];
        ans = bm-am+1;

    }else
    {
        am = a[n / 2];
        bm = b[n / 2];
        ans = bm-am+1;
    }
    cout << ans << endl;

}