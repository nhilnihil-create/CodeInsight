#include <iostream>
using namespace std;
int a[100005];

int main() {
    int n;
    cin>> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        a[tmp] = i;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}
