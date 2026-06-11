#include <bits/stdc++.h>

#define ed cout << "\n";
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ffor(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(i, n) ffor(i, 0, n)
#define All(obj) (obj).begin(), (obj).end()
#define INF ((ll)1e9 + 7)
#define c(a) cout << a << "\n";
using namespace std;
const int N = 100005;

int main()
{
    speed;
    cout << fixed << setprecision(6);
    /*start*/
    int n;
    int k;
    cin >> n >> k;
    map<int, int> m;
    rep(i, n) m[i] = 0;
    rep(i,k){
        int d;
        cin >> d;
        rep(i,d){
            int a;
            cin >> a;
            m.at(a - 1)++;
        }
    }
    int res = 0;
    rep(i,n){
        if(m[i]==0)
            res++;
    }
    c(res);
}
