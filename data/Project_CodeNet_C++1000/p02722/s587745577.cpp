# include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    set <long long> s;
    cin >> n;

    s.insert(n);

    long long x = n - 1;

    if (x >= 2)
        s.insert(x);

    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            s.insert(i);
            if (x / i != i)
                s.insert(x / i);
        }
    }

    for (long long i = 2; i * i <= n; i++) {
        long long y = n;
        while (y % i == 0){
            y /= i;
        }
        if ((y - 1) % i == 0)
            s.insert(i);
    }

    cout << s.size() << endl;
}
