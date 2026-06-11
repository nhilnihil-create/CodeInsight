#include <bits/stdc++.h>
int main() {
    bool arr[31];
    std::memset(arr, 0, sizeof (arr));
    int t;
    for (int i = 0; i < 28; i++) {
        std::scanf("%d", &t);
        arr[t] = true;
    }
    for (int i = 1; i <= 30; i++) {
        if (!arr[i]) std::printf("%d\n", i);
    }
    return 0;
}
