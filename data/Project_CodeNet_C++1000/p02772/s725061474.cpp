#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;

        if (a%2==0 && (a%5 && a%3)) {
            cout << "DENIED";
            return 0;
        }
    }

    cout << "APPROVED";

    return 0;
}
