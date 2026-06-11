#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> plus, minus;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        plus.push_back(x + y);
        minus.push_back(x - y);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    cout << max(plus[N - 1] - plus[0], minus[N - 1] - minus[0]) << endl;
    return 0;
}