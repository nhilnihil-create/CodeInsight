#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n;
string s;

vector<int> Z_algorithm(string x) {
    int xc = 0, xlen = x.length();
    vector<int> Z(xlen, 0);
    for(int i = 1; i < xlen; ++i) {
        int l = i-xc;
        if(i+Z[l] < xc+Z[xc]) Z[i] = Z[l];
        else {
            int j = max(0, xc+Z[xc]-i);
            while(i+j < n && x[j] == x[i+j]) ++j;
            Z[i] = j;
            xc = i;
        }
    }
    Z[0] = xlen;
    return Z;
}


int main() {
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        string ch = s.substr(i, n-i);
        vector<int> ansvec = Z_algorithm(ch);
        /*cout << "ansvec ";
        for(int j = 0; j < (int)ansvec.size(); ++j) {
            cout << ansvec.at(j) << " ";
        }
        cout << endl;*/
        for(int j = 1; j < (int)ansvec.size(); ++j) {
            chmax(ans, min(ansvec.at(j), j));
        }
    }
    cout << ans << endl;
}