#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>

#define DIV 1000000007
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int& x : a)
        cin >> x;

    vector<int>cnt(N);
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        cnt[a[i]]++;
        if (a[i] == 0) {
            ans *= (3 - cnt[a[i]] + 1);
        }
        else
            ans *= (cnt[a[i] - 1] - cnt[a[i]] + 1);
        if (ans <= 0)break;
        ans %= DIV;
        //cout << ans << endl;
    }
    cout << ans << endl;
}
