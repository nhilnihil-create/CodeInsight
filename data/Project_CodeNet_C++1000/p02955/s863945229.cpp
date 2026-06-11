#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

bool isPrime(long long x) {
    if (x == 1) return true;
    for (long long i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

vector<long long> common_divisors(long long a, long long b) {
    long long n = gcd(a, b);
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(n / i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}
vector<int> get_divisors(long long n) {
    vector<int> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(n / i);
                ans.push_back(i);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    return ans;
}

bool is_sorted(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) return false;
    }
    return true;
}

int mxN = 1e5;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long sum = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> div = get_divisors(sum);
    for (int t = 0; t < div.size(); t++) {
        int d = div[t];
        long long total = 0;
        vector<int> remainders;
        for (int i = 0; i < n; i++) {
            remainders.push_back(a[i] % d);
        }
        sort(remainders.begin(), remainders.end());
        int i = 0;
        while (i < (int)remainders.size() && remainders[i] == 0) i++;
        int j = (int)remainders.size() - 1;
        while (i < (int)remainders.size() && i < j) {
            int sum = min(d - remainders[j], remainders[i]);
            remainders[i] -= sum;
            remainders[j] += sum;
            if (remainders[i] == 0) i++;
            if (remainders[j] == d) j--;
            total += sum;
        }
        if (total <= k) {
            ans = d;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}