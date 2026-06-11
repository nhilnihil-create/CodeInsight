#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    ll N, M, V, P;
    cin >> N >> M >> V >> P;

    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());
    int ans = P;
    ll total = a[P-1];
    for (int i = P; i < N; i++) {
        //cout << "i=" << i << endl;
        ll noo = i - (P - 1);
        if (N - noo >= V) {
            if (a[i] + M >= a[P - 1])
                ans++;
            //else
              //  break;
        }

        else {
            if (max(a[P-1],(total + M*(V - (N - noo)) + (noo - 1)) / noo) <= a[i] + M)
                ans++;
        }
        total += a[i];
    }

    cout << ans << endl;
}