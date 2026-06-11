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
char k[3] = {'R', 'U', 'D'};
char g[3] = {'L', 'U', 'D'};
int main()
{
    string s;cin >> s;
    rep(i,sz(s))
    {
        if((i+1)%2==1)
        {
            bool flag = false;
            for (auto &&c : k)
            {
                if(s[i]==c)
                {
                    flag = true;
                }
            }
            if(!flag)
            {
                cout << "No" << endl;
                return 0;
            }
            
        }
        if ((i + 1) % 2 == 0)
        {
            bool flag = false;
            for (auto &&c : g)
            {
                if (s[i] == c)
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}