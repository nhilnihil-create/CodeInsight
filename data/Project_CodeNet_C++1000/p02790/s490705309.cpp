#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    for (int i = 0; i < b; i++) {
		printf("%d", a);
	}
    return 0;
}
