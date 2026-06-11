#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int n , a[N];
int main() {
    abdelrahman010
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        if(i != x)
            cnt++;
    }
    if(cnt == 2 || cnt == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}