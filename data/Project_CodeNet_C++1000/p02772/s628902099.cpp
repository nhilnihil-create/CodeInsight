#include <bits/stdc++.h>
using namespace std;

int main() {
    set<long long>s;
    int len;
    cin >> len;
    while(len--){
        long long ai;
        cin >> ai;
        if(ai % 2 == 0 && (ai % 3 != 0 && ai % 5 != 0)){
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;
}