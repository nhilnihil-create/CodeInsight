#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>

using namespace std;

bool check(string s) {

    int l = 0;
    int r = s.size()/2;

    while(r != s.size()) {
        if(s[l] != s[r]) {
            return false;
        }
        l++;
        r++;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n % 2 != 0) {
        cout << "No" << endl;
    }
    else {
        if(check(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    } 

    //cout << a[0]<< b[1] << c[2] << endl;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}