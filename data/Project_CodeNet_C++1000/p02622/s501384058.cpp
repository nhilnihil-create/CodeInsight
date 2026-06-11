#include <bits/stdc++.h>


using namespace std;
using ll = long long;


int main() {
    string a, b;
    cin >> a >> b;
    int res = 0;
    for(int i = 0; i < (int) a.length(); i++) {
        if(a[i] != b[i]) {
            res++;
        }
    }
    cout << res << "\n";



    return 0;
}

