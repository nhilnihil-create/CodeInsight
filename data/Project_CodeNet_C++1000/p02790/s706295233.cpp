#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int a,b;
    cin >> a >> b;
    string c = "";
    string d = "";
    rep(i,b) {
        c += a+'0';
    }
    rep(i,a) {
        d += b+'0';
    }
    if(c<=d) cout << c << endl;
    else cout << d << endl;
}