#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

using ll = long long;

int main() {
    // freopen("g.txt", 'r', stdin);
    // fastio;

    int n;
    scanf("%d", &n);

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &arr[i].first);
        arr[i].second = i+1;
    }

    sort(begin(arr), end(arr));

    for (auto e : arr)
        printf("%d ", e.second);
    puts("");

    return 0;
}

