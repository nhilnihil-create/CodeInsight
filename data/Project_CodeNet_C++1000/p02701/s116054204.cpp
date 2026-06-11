#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<string> items;
    string item;
    for (int i = 0; i < n; i++) {
        cin >> item;
        items.insert(item);
    }
    cout << items.size();
}
