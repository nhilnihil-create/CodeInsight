#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    bool ans = false;
    double check = double(sum) / (4*double(m));

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int cnt = 0;

    for(int i=0; i<m; i++) {
        if(a[i] >= check) cnt++;
    }

    if(cnt == m) ans = true;

    if(ans) puts("Yes");
    else puts("No");
}