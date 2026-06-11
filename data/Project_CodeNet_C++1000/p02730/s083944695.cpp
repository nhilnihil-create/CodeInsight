#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll oo = 1e18;
const ll mod = 998244353,maxn = 3030;
const double PI = acos(-1);


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;

    int n = s.size(), l = 1, r = s.size();
    bool impossible = false;

    while (l < r){
        if (s[l-1] != s[r-1]) impossible = true;
        l++, r--;
    }
    l = 1, r = (n-1)/2;

    while (l < r){
        if (s[l-1] != s[r-1]) impossible = true;
        l++, r--;
    }

    l = (n+3)/2, r = n;
    while (l < r){
        if (s[l-1] != s[r-1]) impossible = true;
        l++, r--;
    }

    if (impossible) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}