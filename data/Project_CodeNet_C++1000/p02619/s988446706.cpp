#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, manzoku;
    cin >> D;
    vector<int> c(26, 0);
    vector<int> count(26, 0);
    vector<vector<int>> s(D, vector<int>(26));

    for(int i = 0; i < 26; i++){
        cin >> c[i];
    }

    for(int i = 0; i < D; i++){
        for(int n = 0; n < 26; n++){
            cin >> s.at(i).at(n);
        }
    }

    vector<int> t(D, 0);
    for(int i = 0; i < D; i++){
        cin >> t[i];
        t[i] -= 1;
    }

    for(int i = 0; i < D; i++){
        manzoku += s.at(i).at(t[i]);
        for(int n = 0; n < 26; n++){
            if(n == t[i]){
                count[n] = 0;
            }else{
                count[n] += 1;
            }
            manzoku -= count[n] * c[n];
        }
        cout << manzoku << endl;
    }
}