#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;


int main(){
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> a(x);
    vector<int> b(y);
    vector<tuple <int, int, int>> M(z);
    int minA = 5000000;
    rep(i, x){
        cin >> a.at(i);
        minA = min(a.at(i), minA);
    }
    int minB = 5000000;
    rep(i, y){
        cin >> b.at(i);
        minB = min(b.at(i), minB);
    }
    int minCost = minA + minB;

    int xm, ym, cm;
    rep(i, z){
        cin >> xm >> ym >> cm;
        M.at(i) = make_tuple(xm, ym, cm);
    }
    for (auto mi: M){
        tie(xm, ym, cm) = mi;
        minCost = min(minCost, a[xm-1] + b[ym-1] - cm);
    }
    cout << minCost << endl; 
}