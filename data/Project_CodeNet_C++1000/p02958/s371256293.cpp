#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;

    cin >> num;

    vector<int> vec(num);
    vector<int> vec2(num);

    for (int i = 0; i < num; i++) cin >> vec.at(i);

    vec2 = vec;
    sort(vec2.begin(), vec2.end());

    int cnt = 0;
    for (int i = 0; i < num; i++) {
        if (vec.at(i) != vec2.at(i)) cnt++;
    }

    if (cnt <= 2) cout << "YES";
    else cout << "NO";
    //
}
