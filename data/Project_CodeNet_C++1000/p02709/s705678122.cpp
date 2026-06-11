#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef unordered_set<int> si;
typedef pair<int, int> pp;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define all(e) (e).begin(), (e).end()


template <typename T>
void printV(vector<T> A) {
    if (A.empty()) cerr << "EMTPY\n";
    else { 
        cerr << "[";
        for (int i = 0; i < A.size() -1 ; ++i) {
            cerr << A[i] << ", ";
        }
        if (A.size()) cerr << A.back() << "]\n";
    }
}


template <typename T>
void printVV(vector<vector<T>> A) {
    cerr << "[";
    for (auto v : A) {
        printV<T>(v);
    }
    cerr << "]";
}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&& ...args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

const int N = 2001;
ll dp[N][N];

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;
    vll arr(n+1);
    vi idx(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        idx[i] = i;
    }

    sort(idx.begin() + 1, idx.end(), [&] (int a, int b) {
        return arr[a] > arr[b];
    });

    memset(dp,0,sizeof(dp));

    for (ll i = 1; i <= n; ++i) {
        ll pos = idx[i];
        ll val = arr[pos];
        for (int j = 0; j <= i-1; ++j) {
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + val * abs(pos - (j+1)));
            dp[i][j] = max(dp[i][j], dp[i-1][j] + val * abs(pos - (n - i + j + 1)));
        }
        cout << endl;
    }

    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << '\n';
   
    return 0;
}

