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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n,k;
    cin >> n >> k;
    if (k>(n-1)*(n-2)/2)
    {
        cout << -1 << endl;
        return 0;
    }
    
    vector<P> vc;
    for (int i = 2; i < n+1; i++)
    {
        vc.push_back(P{1,i});
    }
    int add = (n-1)*(n-2)/2-k;
    for (int i = 2; i < n+1; i++)
    {
        for (int j = i+1; j < n+1; j++)
        {
            if (add==0)
            {
                break;
            }
            vc.push_back(P{i, j});
            add--;
        }
        if (add == 0)
        {
            break;
        }
    }
    

    cout << sz(vc) << endl;
    rep(i,sz(vc))
    {
        cout << vc[i].first << " " << vc[i].second << endl;
    }
}