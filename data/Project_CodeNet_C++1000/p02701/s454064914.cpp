#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    set<string> S;
    string item;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> item;
        S.insert(item);
    }

    cout << S.size() << endl;

}
