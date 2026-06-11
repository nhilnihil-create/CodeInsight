#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;
        a[i] = t;
    }
    sort(a.begin(), a.end());
    int ng = 0;
    int ok = a[n-1];
    while (abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        long long cnt = 0;
        for (int i = 0; i < n; ++i){
            cnt += (a[i] - 1) / mid;
        }
        if(k >= cnt){
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}