#include <bits/stdc++.h>
using namespace std;

int main(){
    long long h, n;
    cin >> h >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        h -= a[i];
    }
    if(h <= 0) puts("Yes");
    else puts("No");
}