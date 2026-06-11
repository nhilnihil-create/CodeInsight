#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int a;
    cin >> a;
    string b;
    cin >> b;
    int hundred_b = (b[0]-'0')*100 + (b[2]-'0')*10 + b[3]-'0';
    cout << a * hundred_b / 100 << endl;

    return 0;
}