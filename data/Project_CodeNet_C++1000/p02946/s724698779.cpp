#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)


int main() {
    int k,x;
    cin >> k >> x;
    rep(i,2*k-1) {
        printf("%d ", x-k+1+i);
    }
    printf("\n");
    return 0;
}
