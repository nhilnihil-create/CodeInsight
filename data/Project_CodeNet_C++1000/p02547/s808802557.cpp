#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) v.push_back(i);
    }
    for (int i = 2; i < v.size(); i++) {
        if (v[i]-1 == v[i-1] && v[i-1]-1 == v[i-2]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}