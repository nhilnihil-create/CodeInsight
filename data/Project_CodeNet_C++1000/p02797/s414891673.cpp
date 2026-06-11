#include <bits/stdc++.h>
using namespace std;

// loop macro
#define PER(ITER,TIMES) for(auto ITER = 0; ITER < TIMES; ++ITER)

// helper macro
#define FUCK(IT) #IT": " << IT << ": "
#define ALL(ITER) ITER.begin(), ITER.end()

void solve(void);

/* --- MAIN PART ----------------------------------------------------------- */

#define SOLVE_F
#ifdef SOLVE_E

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    PER(i, n) {
        cin >> a[i];
    }
    sort(ALL(a), [](const int& a, const int& b){return a > b;});
    int result = a[0];
    PER(i, (a.size() - 2) / 2) {
        result += 2 * a[i + 1];
    }
    if ((a.size() - 2) % 2) {
        result += a[(a.size() - 2 / 2) + 1];
    }
    cout << result;
    return;
}

#endif

#ifdef SOLVE_F

void solve(void) {
    int n, m, sum;
    cin >> n >> m >> sum;
    PER(i, m) {
        cout << sum << " ";
    }
    PER(i, n - m) {
        cout << (sum > 100 ? sum / 2 + 2 : sum + 1) << " ";
    }
    return;
}

#endif

#ifdef SOLVE_B

long long times (const vector<long long>& sorted, long long len) {
    long long result = 1;
    PER (i, len) {
        result *= sorted[i];
    }
    return result;
}

void solve(void){
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    PER(i, n) {
        cin >> a[i];
    }

    vector<long long> up, down;
    PER(i, n) {
        if (a[i] > 0) {
            up.push_back(a[i]);
        } else if (a[i] < 0) {
            down.push_back(a[i] = -a[i]);
        }
    }

    long long result = 0;
    if ((k % 2 == 1 && up.size() == 0) || (down.size() == 1 && up.size() == k - 1)) {
        if (up.size() + down.size() != a.size()) {
            result = 0;
        } else {
            sort(ALL(a));
            for (int i = 0; i < k; ++i) {
                result += -a[i];
            }
            while (result < 0) {
                result += (long long) 1e9 + 7;
            }
        }
    } else {
        sort(ALL(up), [](const long long& a, const long long& b){return a > b;});
        sort(ALL(down), [](const long long& a, const long long& b){return a > b;});

        for(long long i = 0; i <= down.size(); i += 2) {
            long long _ = times(up, k - i) * times(down, i);
            result = (result > _ ? result : _);
            result %= (long long)1e9 + 7;
        }
    }

    cout << result << endl;

    return;
}

#endif // for solve

/* ------------------------------------------------------------------------- */

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

