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
ll K;

bool check(ll X,vector<ll>&a,vector<ll>&f){
    ll total = 0;
    int N = a.size();

    for (int i = 0; i < N; i++) {
        if (a[i] * f[i]  <= X) continue;
        total += (a[i] * f[i] - X + (f[i] - 1)) / f[i];
    }

    if (total <= K) return true;
    else return false;

}

int main() {
    ll N;
    cin >> N >> K;

    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> f(N);
    for (int i = 0; i < N; i++)
        cin >> f[i];
    sort(f.begin(), f.end(), greater<ll>());

    ll left = 0, right = 1e12;
    while (left != right) {
        ll mid = (left + right) / 2;
        if (check(mid,a,f)) right = mid;
        else left = mid+1;
       // cout << "mid= " << mid << endl;
    }

    cout << left << endl;
}