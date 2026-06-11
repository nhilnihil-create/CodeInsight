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

    int n, k;

    cin >> n;
    cin >> k;

    int a[n];
    rep(i, n)
    {
        cin >> a[i];
    }

    int l = 0;
    int r = 1e9;

    while(r-l>1)
    {
        int mid = (r+l)/2;

        auto judge = [&](int val)
        {
            ll count = 0;
            rep(i, n)
            {
                count += (a[i]-1)/val;
            }
            return count <= k;

        };

        if(judge(mid))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    
    cout << r << endl;





    return 0;

}
