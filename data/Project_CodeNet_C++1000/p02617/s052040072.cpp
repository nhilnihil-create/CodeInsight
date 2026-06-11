#include<iostream>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<sstream>
#include<algorithm>
//#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans += (i*(i+1))/2;
    }

    long long a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;

        if (a > b) swap(a, b);

        ans -= (a*(n-b+1));
    }

    cout << ans << endl;
    
    return 0;
}
