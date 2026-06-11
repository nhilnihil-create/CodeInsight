#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

int main() {
    int N;
    int K;
    
    scanf("%d%d", &N, &K);
    
    int ans = 0;
    
    while (N > 0) {
        N /= K;
        ans += 1;
    }
    
    printf("%d\n", ans);
	
	return 0;
}