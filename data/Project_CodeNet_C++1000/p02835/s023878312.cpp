#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b + c >= 22) {
        printf("bust");
    } else {
        printf("win");
    }
    return 0;
}
