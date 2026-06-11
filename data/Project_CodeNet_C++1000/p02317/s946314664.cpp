#include <cstdio>
#include <limits>
#include <algorithm>

int n, arr[100010];
constexpr int inf = std::numeric_limits<int>::max();
int main() {
    int i;
    scanf("%d", &n);
    std::fill(arr, arr + n, inf);
    
    int tmp, len = 0;
    for(i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        
        auto * it = std::lower_bound(arr, arr + n, tmp);
        
        *it = tmp;
        
        len = std::max<int>(len, it - arr + 1);
    }
    
    printf("%d\n", len);
}