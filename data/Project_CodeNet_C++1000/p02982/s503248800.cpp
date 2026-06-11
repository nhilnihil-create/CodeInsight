#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, D;
    cin >> N >> D;
    vector<vector<int> > dot(N,vector<int>(D,0));
    int ans = 0;
    int temp;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < D; j++) {
            cin >> dot.at(i).at(j);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            temp = 0;
            for(int k = 0; k < D; k++) {
                temp += (int)pow(dot.at(i).at(k) - dot.at(j).at(k), 2);
            }
            for(int k = pow(temp, 0.5) -  4; k < pow(temp, 0.5) + 4; k++) {
                if(k*k == temp) {
                    ans++;
                    break;
                }
            }
            //cout << temp << endl;
        }
    }

    cout << ans << endl;


    return 0;
}