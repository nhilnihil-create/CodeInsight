#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
#define pri(str) cout << str << endl
using ll = long long;
using P = pair<int, int>;

const ll MX = 1e18;
const long double PI = acos(-1);

int main()
{
    int n, k, R, S, P;
    string t;
    cin >> n >> k >> R >> S >> P >> t;
    ll point = 0;
    ll pre_point = 0;
    rep(i,n)
    {
        pre_point = point;
        
        if(t[i] == 'r')
            point += P;
        else if(t[i] == 's')
            point += R;
        else
            point += S;

        if(i-k >= 0)
            if(t[i] == t[i-k])
            {
                t[i] = 'a';
                point = pre_point;
            }   
    }
    pri(point);
        
    return 0;
}
