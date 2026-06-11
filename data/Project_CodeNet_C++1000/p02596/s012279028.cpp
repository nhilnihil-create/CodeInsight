#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define FILL0(x) memset(x,0,sizeof(x))
#define FILL1(x) memset(x,-1,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll k;
    cin >> k;

    ll r=0;
    //10^1000000までにはあるだろう
    rep(i, 10000000)
    {
        r=(r%k)*10+7;
        if(r%k==0)
        {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;



    return 0;

}
