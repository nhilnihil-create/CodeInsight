#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int x[60], y[60];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    map<pair<int, int>, int> mp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                mp[make_pair((x[i] - x[j]), (y[i] - y[j]))]++;
            }
        }
    }

    int max_val = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        int val = itr->second;
        //pair<int, int> k = itr->first;
        //cout << k.first << " " << k.second << " " << val << endl;
        max_val = max(max_val, val);
    }
 
    cout << N - max_val << endl;

    return 0;
}
