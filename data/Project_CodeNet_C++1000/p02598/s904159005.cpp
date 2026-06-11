#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    int low = 0, high = 1000000010;
    while(high - low > 1) {
        int len = (high + low)/2;
        long long int cut_num = 0;
        for(int i = 0; i < n; ++i) {
            cut_num += (a[i]-1)/len;
        }
        if(cut_num <= k) high = len;
        else low = len;
    }
    cout << high << '\n';
}
