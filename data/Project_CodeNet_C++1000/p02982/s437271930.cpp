#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    vector<vector<int>> coo(n, vector<int>(d));
    for(int i =0; i < n; i++) {
        for(int j = 0; j < d; j++) cin >> coo.at(i).at(j);
    }
    int ans =0;

    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dis2 = 0;
            for (int k = 0; k < d; k++) {
                dis2 += pow((coo.at(i).at(k) - coo.at(j).at(k)), 2);
            }

            for(int k = 0; k < 130; k++) {
                if (dis2 == k * k) {
                    ans++;
                    break;
                    }
            }
        }
    }

    cout << ans << endl;
}