#include <iostream>
using namespace std;
#define ll long long
int a[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    ll s = 0;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        s += a[i] * flag;
        flag *= -1;
    }
    printf("%d ", s);
    for (int i = 1; i < n; i++) {
        s = 2 * a[i] - s;
        printf("%d ", s);
    }
}

