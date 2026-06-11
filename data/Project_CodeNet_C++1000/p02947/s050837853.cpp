#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int n; 
    scanf("%d", &n);

    string t;
    map<string, int> mp;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        sort(t.begin(), t.end());
        mp[t]++;
        ans += mp[t] - 1;
    }

    cout << ans << endl;
}