#include <bits/stdc++.h>

using namespace std;

int n , k;

int add (int a , int b) {
    a = (a % k + k) % k;
    b = (b % k + k) % k;
    return (a + b) % k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1 ;i <= n ;i++)
        cin >> a[i];

    map<int , int> mp;
    mp[0]++;

    long long ans = 0;
    vector<int> save(n + 1);
    save[0] = 0;

    int sum = 0;
    for (int i = 1 ;i <= n ;i++) {
        sum = add(sum , a[i]);
        if (i - k >= 0)
            mp[save[i - k]]--;
        ans += mp[add(sum , -i)];
        mp[add(sum , -i)]++;
        save[i] = add(sum , -i);
    }

    cout << ans;
}
