#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long f(vector<double>& a, int x)
{
    long long ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret += ceil(a[i]/x) - 1;
    }
    return ret;
}
int src(vector<double>& a, int k, int l = 1, int r = 1e9)
{
    int x = (l + r) / 2;
    if (x <= 1) return 1;
    long long fx = f(a, x);
    if (f(a, x-1) > k && fx <= k) return x;
    if (fx > k) return src(a, k, x+1, r);
    else        return src(a, k,   l, x);
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    cout << src(a, k) << endl;
}