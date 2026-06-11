#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int k, n;
    cin >> k >> n;
    vector<int> a(n), dist(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++){
        dist.push_back(a[i+1] - a[i]);
    }
    dist.push_back(a[0] + (k - a[n-1]));
    sort(dist.begin(), dist.end());
    cout << k - dist.back() << endl;
    return 0;
}
