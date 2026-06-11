#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 1e9;
    while(abs(l - r) > 1) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++) cnt += (a[i] - 1) / mid;
        if(cnt <= k) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}
