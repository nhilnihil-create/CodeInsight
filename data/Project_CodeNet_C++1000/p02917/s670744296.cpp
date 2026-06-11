#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<i64> b(n-1);
    for(auto&& x:b)cin >> x;
    vector<i64> a(n);
    i64 ret = 0;
    a[0] = b[0];
    for(int i=0;i<n-1;i++){
        a[i] = min(a[i], b[i]);
        a[i+1] = max(a[i+1], b[i]);
    }
    for(auto&& x:a)ret += x;
    cout << ret << endl;
    return 0;
}