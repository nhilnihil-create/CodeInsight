#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll S;
    cin >> S;
    ll x1,y1,x2,y2;

    ll t = 1000000000;
    ll tmp;
    if (S%t!=0) {
        tmp = S + t;
    }
    else {
        tmp = S;
    }

    x1 = t;
    y2 = tmp/t;

    ll res = x1*y2 - S;
    x2 = res;
    y1 = 1;

    cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;


}
