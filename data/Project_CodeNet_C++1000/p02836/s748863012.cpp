#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950


int main () {
    string s;
    cin >> s;
    string a;
    a = s;
    reverse(s.begin(), s.end());
    int t = s.size() / 2 ;
    int ans = 0;
    rep (i, t){
        if (s[i] != a[i]){
            ans++ ;
        }
    }
    cout << ans << endl;
}