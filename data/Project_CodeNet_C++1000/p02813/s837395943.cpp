#include <bits/stdc++.h>

using namespace std;

const int N = 9;
int memo[N][1 << N] , n;

int solve (int i , int msk) {
    if (i == n)
        return 1;

    int &ret = memo[i][msk];
    if (~ret)
         return ret;

    ret = 0;
    for (int j = 0 ;j < n ;j++)
        if (!(msk & (1 << j)))
            ret += solve(i + 1 , msk | (1 << j));

    return ret;
}

int get(vector<int> &a) {
    auto fact = [](int n) {
        int ret = 1;
        for (int i = 2 ;i <= n ;i++)
            ret *= i;
        return ret;
    };

    int less = 0 , msk = 0;
    for (int i = 0 ;i < n ;i++) {
        for (int j = 0 ;j < a[i] ;j++)
            if (!(msk & (1 << j)))
                less += solve(i + 1 , msk | (1 << j));
        msk |= 1 << a[i];
    }

    return less + 1;
}

int main() {
    cin >> n;

    vector<int> a(n) , b(n);
    for (int i = 0 ;i < n ;i++) {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0 ;i < n ;i++) {
        cin >> b[i];
        b[i]--;
    }

    memset(memo , -1 , sizeof memo);
    cout << abs(get(a) - get(b));
}
