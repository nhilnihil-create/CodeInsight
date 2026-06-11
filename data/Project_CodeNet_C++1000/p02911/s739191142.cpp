#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> score(n, k - q);

    int temp;
    rep(i, q) {
        cin >> temp;
        score[temp - 1]++;
    }

    rep(i, n) {
        if(score[i] > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}