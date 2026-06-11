#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> a(3, vector<int>(3));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a.at(i).at(j);
        }
    }
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b.at(i);
    for(int B : b) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(a.at(i).at(j) == B) {
                    a.at(i).at(j) = 0;
                }
            }
        }
    }
    bool c = 0;
    if(a.at(0).at(0) == a.at(0).at(1) && a.at(0).at(1) == a.at(0).at(2)) {
        c = 1;
        goto END;
    }
    if(a.at(1).at(0) == a.at(1).at(1) && a.at(1).at(1) == a.at(1).at(2)) {
        c = 1;
        goto END;
    }
    if(a.at(2).at(0) == a.at(2).at(1) && a.at(2).at(1) == a.at(2).at(2)) {
        c = 1;
        goto END;
    }
    if(a.at(0).at(0) == a.at(1).at(0) && a.at(1).at(0) == a.at(2).at(0)) {
        c = 1;
        goto END;
    }
    if(a.at(0).at(1) == a.at(1).at(1) && a.at(1).at(1) == a.at(2).at(1)) {
        c = 1;
        goto END;
    }
    if(a.at(0).at(2) == a.at(1).at(2) && a.at(1).at(2) == a.at(2).at(2)) {
        c = 1;
        goto END;
    }
    if(a.at(0).at(0) == a.at(1).at(1) && a.at(1).at(1) == a.at(2).at(2)) {
        c = 1;
        goto END;
    }
    if(a.at(0).at(2) == a.at(1).at(1) && a.at(1).at(1) == a.at(2).at(0)) {
        c = 1;
        goto END;
    }
END:
    if(c) cout << "Yes" << endl;
    else cout << "No" << endl;
}