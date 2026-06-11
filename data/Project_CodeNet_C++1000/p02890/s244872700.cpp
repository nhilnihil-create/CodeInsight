// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <set>

#define prev asasddlsa
#define rank aljds

using namespace std;

typedef long long ll;

template<typename T>
void print(const vector<T>& s){
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    sort(cnt.begin(), cnt.end());
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + cnt[i];
    for (int k = 1; k <= n; k++){
        int l = 0;
        int r = n + 1;
        while (l + 1 < r){
            ll m = (l + r) / 2;
            int pos = upper_bound(cnt.begin(), cnt.end(), m) - cnt.begin();
            if (pref[pos] + (n - pos) * m >= k * m)
                l = m;
            else
                r = m;
        }
        cout << l << "\n";
    }
    return 0;
}