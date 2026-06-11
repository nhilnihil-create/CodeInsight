#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string last;
    int i=1;
    last = s.substr(0,1);
    int ans = 1;
    while (i < n){
        int k=1;

        while (last == s.substr(i,k)){
            k++;
            if (k > pow(10,7)){
                cout << ans << endl;
                exit(0);
            }
        }
        last = s.substr(i,k);

        i += k;
        ans++;
    }
    cout << ans << endl;
}