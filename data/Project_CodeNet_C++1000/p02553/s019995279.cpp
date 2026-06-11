#include <bits/stdc++.h>

using namespace std;

#define Fast  ios::sync_with_stdio(false); cin.tie(0)
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define S second
#define F first
typedef long long ll;
const int mod = 1e9 + 7;
const ll N = 2e5 + 5;
ll inf = 1e18;


int main(){

    Fast;

    ll a , b , c , d;
    cin >> a >> b >> c >> d;

    ll tmp = max(a*c , a*d);
    tmp = max(tmp , b*c);
    tmp = max(tmp , b*d);

    cout << tmp ;

    return 0;
}
