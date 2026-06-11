#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n, p;
string s;
vector<long long> cnt(10100, 0);

int main() {
    cin >> n >> p >> s;
    cnt.at(0) = 1;
    if(p == 2 || p == 5) {
        if(p == 2) {
            long long cnt2 = 0;
            for(int i = n-1; i >= 0; --i) {
                if((s.at(i) - '0') % 2 == 0) {
                    cnt2 += (i+1);
                }
            }
            cout << cnt2 << endl;
        }else {
            long long cnt5 = 0;
            for(int i = n-1; i >= 0; --i) {
                if((s.at(i) - '0') % 5 == 0) {
                    cnt5 += (i+1);
                }
            }
            cout << cnt5 << endl;
        }
    }else {
        long long power = 1;
        long long ans = 0;
        long long amari = 0;
        for(int i = n-1; i >= 0; --i) {
            amari = (amari + (s.at(i) - '0')*power) % p;
            ans += cnt.at(amari);
            power = (power*10) % p;
            cnt.at(amari)++;
        }
        cout << ans << endl;
    }

}