#include <bits/stdc++.h>

using namespace std;
using ll = long long;
//batyanotame,nishuume

int main() {
    vector<vector<int> > A(3,vector<int>(3,0));
    vector<vector<bool> > Abool(3,vector<bool>(3,0));
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A.at(i).at(j);
        }
    }
    int N = 0;
    cin >> N;
    vector<int> B(N,0);
    for(int i = 0; i < N; i++) {
        cin >> B.at(i);
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(A.at(j).at(k) == B.at(i)) {
                    Abool.at(j).at(k) = 1;
                    //cout << i << ' ' << j << ' ' << k << endl;
                }
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        //cout << ans << endl;
        if(Abool.at(i).at(0) && Abool.at(i).at(1) && Abool.at(i).at(2)) {
            ans++;
        }
        if(Abool.at(0).at(i) && Abool.at(1).at(i) && Abool.at(2).at(i)) {
            ans++;
        }
        if(Abool.at(0).at(0) && Abool.at(1).at(1) && Abool.at(2).at(2)) {
            ans++;
        }
        if(Abool.at(2).at(0) && Abool.at(1).at(1) && Abool.at(0).at(2)) {
            ans++;
        }
    }
    if(ans) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }
    





    return 0;
}