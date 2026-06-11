#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

long double A,B,H,M;

void solve(){

    cin >> A >> B >> H >> M;

    // 6 grad pro min   30 grad por hour

    long double arc = 6*M-(30*H+(6*M)/12);
    arc = abs(arc);
    //cout << "arc : " << arc << " cos: " << cos(arc * PI / 180.0) << endl;

    long double  ans = (A*A+B*B)- (long double)(2*A*B * cos(arc * PI / 180.0));

    cout << setprecision(20) << sqrt(ans) << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}