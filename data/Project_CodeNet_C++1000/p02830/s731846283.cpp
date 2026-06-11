#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 102;
char s[N], t[N];

int main() {
    int n;
    scanf("%d\n%s\n%s", &n, s, t);
    string res = "";
    for (int i = 0; i < n; i++) {
        res += s[i];
        res += t[i];
    }
    printf("%s", res.c_str());
    return 0;
}
