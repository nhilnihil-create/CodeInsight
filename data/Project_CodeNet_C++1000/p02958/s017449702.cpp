#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

using ll = long long;

int main() {
    // freopen('a.txt', 'r', stdin);
    // fastio;
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int& e : arr)
        scanf("%d", &e);

    bool ok = is_sorted(arr, arr+n);

    if (ok)
        goto ans;

    for (int x = 0; x < n; x ++) {
        for (int y = x+1; y < n; y ++) {
            swap(arr[x], arr[y]);
            if (is_sorted(arr, arr+n)) {
                ok = true;
                goto ans;
            }
            swap(arr[x], arr[y]);
        }
    }

ans:
    if (ok)
        puts("YES");
    else
        puts("NO");

    return 0;
}

