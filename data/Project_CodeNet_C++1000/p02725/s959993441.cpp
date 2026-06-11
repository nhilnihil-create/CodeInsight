#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n;
    cin >> k >> n;
    int d_max = 0;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n - 1; ++i){
        d_max = max(d_max, abs(a[i + 1] - a[i]));
    }

    d_max = max(d_max,a.front() + (k - a.back()));

    cout << k - d_max << endl;

    return 0;
}