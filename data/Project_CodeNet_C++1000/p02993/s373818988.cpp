#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {

    string S;
    cin >> S;

    string a,b;
    rep(i,3){
        a = S[i];
        b = S[i+1];
        if(a == b){
            cout << "Bad" << endl;
            return 0;
        }
    }

    cout << "Good" << endl;
    return 0;
}