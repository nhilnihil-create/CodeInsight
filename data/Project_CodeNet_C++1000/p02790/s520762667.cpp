#include <bits/stdc++.h>
using namespace std;
int main(){
        int a, b; cin >> a >> b;
        for (int x = 0; x < max(a, b); ++x) cout << min(a, b);
    return 0;
}

