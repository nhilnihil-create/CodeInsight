#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const lli mod = 1e9;
lli s;

int main(void){
    cin >> s;
    vector<lli> x(3), y(3);
    x[0] = y[0] = 0;
    x[1] = 1e9, y[1] = 1;
    y[2] = (s+mod-1)/mod;
    x[2] = mod*y[2]-s;
    //assert(abs(x[1]*y[2]-x[2]*y[1]) == s);
    rep(i, 3) cout << x[i] << " " << y[i] << " ";
    cout << endl;
    return 0;
}
