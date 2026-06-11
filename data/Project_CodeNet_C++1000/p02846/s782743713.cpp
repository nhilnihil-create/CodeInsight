#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef __int128 ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define ALL(c) (c).begin(), (c).end()
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t1,t2;cin >> t1>>t2;
    ll a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;

    ll ichiban = t1 * (a1 - b1);
    ll niban = t2 * (a2 - b2);
    ll gokei = ichiban + niban;
    // cout << ichiban << endl;
    // cout << niban << endl;
    // cout << gokei << endl;
    if(gokei==0 || ichiban == 0)
    // if(gokei==0)
    {
        cout << "infinity" << endl;
    }
    else
    {
        if (gokei < 0)
        {
            ichiban *= -1;
            niban *= -1;
            gokei *= -1;
        }
        if (gokei > 0 && ichiban > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            ll tmp_num = floor(abs(ichiban)/abs(gokei));
            // cout << tmp_num << endl;
            if (tmp_num*gokei==-1 * ichiban)
            {
                cout << tmp_num * 2 << endl;
            }
            else
            {
                cout << tmp_num * 2 + 1 << endl;
            }
        }
        



    }
}


