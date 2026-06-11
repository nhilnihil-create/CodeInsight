#include <bits/stdc++.h>

#define f first
#define sec second
#define pb push_back
#define endl '\n'
#define all(a) begin(a),end(a)
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << endl;
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define fori(i, a, b) for(int i(a), ThkMk(b); i <= ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef unsigned long long ulli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

///-----------------------------------------------------------
///-----------------------------------------------------------



///-----------------------------------------------------------

int main()
{   _

    int h, w, k, suma = 0, totalFormas = 0;
    cin >> h >> w >> k;
    vector<int> mat(h, 0);
    for (int i=0; i<h; ++i)
    {
        for (int j=0; j<w; ++j)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
            {
                mat[i] += (1 << j);
                ++suma;
            }
        }
    }
    int TH = (1 << h);
    int TW = (1 << w);
    for (int i=0; i<TH; ++i)
    {
        for (int j=0; j<TW; ++j)
        {
            int quitados = 0;
            for (int k=0; k<h; ++k)
            {
                for (int l=0; l<w; ++l)
                {
                    if (mat[k] & (1 << l) && (i & (1 << k) || j & (1 << l)))
                        ++quitados;
                }
            }
            if (suma - quitados == k)
                ++totalFormas;
        }
    }
    cout << totalFormas << endl;

    return 0;
}