#include <bits/stdc++.h>
using namespace std;

// 1 2 3 4 5
int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    int all = 0;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v[i] = a;
        all ^= a;
    }
    for(int i = 0;i < n;i++){
        int a = all ^ v[i];
        cout << a << " ";
    }
}