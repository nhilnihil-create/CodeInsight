#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void){
    double L; cin >> L;
    double a=L/3,b=L/3,c=L/3;
    double ans = a*b*c;
    //cout << ans << endl;
     //小数点以下の長さを指定
    cout << fixed << setprecision(14) << ans << endl;
}