#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ld long double
#define ff first
#define ss second

using namespace std;

bool verify(int x, int y, int z) {

    if(x > y && y > z)
        return true;

    if(x < y && y < z)
        return true;

    return false;
}

int total_num(const vector<int> &v, int n) {
    int total = 0;

    for(int i = 1; i < n - 1; i++) {
        if(verify(v[i - 1], v[i], v[i + 1]))
            total++;
    }

    return total;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    int r = total_num(v, n);

    cout << r << endl;

    return 0;
}