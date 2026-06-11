#include <bits/stdc++.h>

using namespace std;



void solver() {
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i = 0; i < k; ++i) sum += a[i];
    cout << sum << '\n';
}

int main() {

    ios_base :: sync_with_stdio(0); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    
    while(t--)
        solver();

    return 0;
}