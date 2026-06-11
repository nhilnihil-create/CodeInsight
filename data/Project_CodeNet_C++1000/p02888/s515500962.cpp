#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

vector<int> l;

int binary_search(vector<int> &a, int left, int right, int key) { // // a[i]<keyを満たすiの個数(範囲はleft<=i<=right)
    int ok = left - 1; // 常にtrue
    int ng = right + 1; // 常にfalse
    while (ok + 1 < ng) {
        int mid = (ok + ng) / 2;
        if (a[mid] < key) ok = mid;
        else ng = mid;
    }
    return ok - left + 1;
}

int main() {
    int n;
    cin >> n;
    l.resize(n);
    rep(i, n) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    long sum = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            // sum += binary_search(l, j+1, n-1, l[i]+l[j]) - binary_search(l, j+1, n-1, l[j]-l[i]+1);          
            sum += lower_bound(l.begin()+j+1, l.end(), l[i]+l[j]) - upper_bound(l.begin()+j+1, l.end(), l[j]-l[i]);
        }
    }
    cout << sum << endl;
}