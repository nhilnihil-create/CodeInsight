#include <bits/stdc++.h>

using namespace std;

int main() {
    string t;
    cin >> t;
    for(auto v:t){
        if(v!='?') cout << v;
        else cout << 'D';
    }
    return 0;
}
