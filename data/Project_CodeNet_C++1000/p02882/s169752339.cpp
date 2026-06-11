#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;

int main(){
    double a,b,x;cin >> a >> b >> x;
    double ans;
    if(2*x<=a*a*b) cout << fixed<<setprecision(6) << double(90) - atan(2*x/a/b/b)/M_PI*180 << endl;
    else cout << fixed<<setprecision(6) << atan(2*(a*a*b-x)/a/a/a)/M_PI*180 << endl;
}