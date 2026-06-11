#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
inline bool sortat(vector<int> v) {
    int last(0);
    for (const int& x : v) {
        if (last > x)
            return false;
        last = x;
    }
    return true;
}
vector<int> v;
int n;
int main() {
    DAU
    cin >> n;
    v.resize(n);
    for (int& x : v)
        cin >> x;
 	if (sortat(v)) {
    	cout << "YES";
        PLEC  
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            swap(v[i], v[j]);
            if (sortat(v)) {
                cout << "YES";
                PLEC
            }
            swap(v[i], v[j]);
        }
    cout << "NO";
    PLEC
}
