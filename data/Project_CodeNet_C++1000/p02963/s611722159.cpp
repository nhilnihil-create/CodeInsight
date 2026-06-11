#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll S; cin >> S;
    ll ab = ceil(sqrt(S));
    ll ba = ab * ab - S;
    printf("0 0 %lld 1 %lld %lld\n", ab, ba, ab);
}
