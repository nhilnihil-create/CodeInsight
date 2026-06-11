#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
int main(){
        int a, b; cin >> a >> b;
        if (a >= 2) a = a*(a-1)/2;
        else a = 0;
        if (b >= 2) b = b*(b-1)/2;
        else b = 0;
        cout << a+b << endl;
    return 0;
}

