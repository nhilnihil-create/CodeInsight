#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b)
{
    if (a < b) {
        int k = a;
        a = b;
        b = k;
    }
    if (b == 0) return a;
    return gcd(b, a%b);
}
int p(int n)
{
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) return i;
    }
    return n;
}
int main()
{
    int n, a, s = 0, k;
    bool pwc = true, swc = false;
    vector<bool> f(1'000'001, false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        s = gcd(a, s);
        if (s == 1) swc = true;
        while (pwc && (k = p(a)) != 1) {
            if (f[k]) pwc = false;
            f[k] = true;
            while (a%k == 0) a /= k;
        }
    }
    if (pwc)      cout << "pairwise coprime" << endl;
    else if (swc) cout << "setwise coprime" << endl;
    else          cout << "not coprime" << endl;
}