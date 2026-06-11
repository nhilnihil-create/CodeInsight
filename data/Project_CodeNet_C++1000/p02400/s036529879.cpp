#include<bits/stdc++.h>
using namespace std;
int main(){
    double r, l, s;
    cin >> r;
    l = 2 * M_PI * r;
    s = r * r * M_PI;
    cout << fixed << setprecision(6) << s << " " << l << endl;
    return 0;
}
