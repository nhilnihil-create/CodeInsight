#include<bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    string S;
    cin >> S;

    cout << S;
    
    if(S.back() == 's') {
        cout << "es" << endl;
    } else {
        cout << "s" << endl;
    }
    return 0;
}