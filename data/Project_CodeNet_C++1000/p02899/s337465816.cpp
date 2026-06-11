#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        mp[a] = i;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", mp[i]);
    }
    printf("\n");
    return 0;
}