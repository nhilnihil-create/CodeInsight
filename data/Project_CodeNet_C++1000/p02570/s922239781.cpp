#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;


int32_t main(){

    long double d, t , s ,x  ; cin >> d >> t >> s;
    x = d / s;
    // cout << d << ' ' << t << ' ' << s << ' ' << x << endl;
    if(x <= t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}