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

    int h, w, m;
    cin >> h >> w >> m;
    
    set<P> bomb;
    int yb[h]={0}; 
    int xb[w]={0};



    int xmax=0;
    int ymax=0;
    
    rep(i, m)
    {
        int x, y;
        cin >> y >> x;
        x--;y--;

        xb[x]++;
        yb[y]++;

        bomb.insert(P(y, x));
    }

    rep(i, w)
    {
        if(xmax<xb[i])
        {
            xmax = xb[i];  
        }
    }
    rep(i, h)
    {
        if(ymax<yb[i])
        {
            ymax = yb[i];
        }        
    }

    int ans  = xmax + ymax;

    vector<int> yy, xx;
    rep(i, h)
    {
        if(ymax==yb[i])
        {
            yy.push_back(i);
        }
    }
    rep(i, w)
    {
        if(xmax==xb[i])
        {
            xx.push_back(i);
        }
    }

    rep(i, yy.size())
    {
        rep(j, xx.size())
        {
            if(bomb.count(P(yy[i], xx[j])))
            {
                continue;
            }
            else
            {
                cout << ans << endl;
                return 0;
            }        
        }
    }

    ans--;
    cout << ans  << endl;




    return 0;

}
