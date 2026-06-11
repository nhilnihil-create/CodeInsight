#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll s;
    cin >> s;
    ll tmp = sqrt(s);
    while(tmp*tmp < s) ++tmp;
    while(true){
        if(tmp*tmp == s){
            cout << 0 << " " << 0 << " " << tmp << " " << 0 << " " << 0 << " " << tmp << endl;
            return 0;
        }
        ll x1 = 0, y1 = 0;
        ll x2,y2,x3,y3;
        x3 = tmp;   y2 = tmp;
        ll ss = tmp*tmp - s;
        for(i = 1;i <= sqrt(ss);++i){
            if(ss%i == 0 && ss/i <= 1e9){
                x2 = i, y3 = ss/i;
                if(x3%x2 == 0 && y3%y2 == 0 && x3/x2 == y3/y2) continue;
                cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
                return 0;
            }
        }
        ++tmp;
    }
    return 0;
}