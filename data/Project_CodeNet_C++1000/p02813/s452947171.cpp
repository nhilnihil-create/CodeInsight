#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define printdbl(a) printf("%lf\n", a)
#define printYes() printf("Yes\n")
#define printNo() printf("No\n")
#define scanll(a) scanf("%lld", &a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4Int(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
typedef long long ll;
const int INF = 1001001001;
using namespace std;
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int gdc(int a, int b) {
    int r;
    if (a < b)
        swap(&a, &b);
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int factorial(int a) {
    int ans = 1;
    for (int i = 1; i <= a; ++i) 
        ans *= i;
    return ans;
}

int main() {
    int n;
    scanInt(n);
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vector<int> tmp1(n), tmp2(n);
    rep(i,n) {
        tmp1[i] = i + 1;
        tmp2[i] = i + 1;
    }
    int count1, count2, p1, p2;
    count1 = count2 = p1 = p2 = 0;
    while(!tmp1.empty()) {
        auto res = find(tmp1.begin(), tmp1.end(), p[p1]);
        count1 += (res - tmp1.begin()) * factorial(tmp1.size() - 1);
        p1++;
        tmp1.erase(res);
        res = find(tmp2.begin(), tmp2.end(), q[p2]);
        count2 += (res - tmp2.begin()) * factorial(tmp2.size() - 1);
        p2++;
        tmp2.erase(res);
    }
    printInt(abs(count2 - count1));
    return 0;
}