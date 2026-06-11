#include <bits/stdc++.h>
using namespace std;
int main(){
        int a, b; cin >> a >> b;
        string q = "", w = "";
        for (int x = 0; x < a; ++x) q += '0' + b;
        for (int x = 0; x < b; ++x) w += '0' + a;
        cout << min(q, w) << endl;
    return 0;
}

