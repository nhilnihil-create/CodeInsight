#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ff               first
#define ss               second
#define pb               push_back
#define all(x)           (x).begin(), (x).end()
#define mem0(x)          memset(x, 0, sizeof (x))
#define mem1(x)          memset(x, -1, sizeof (x))

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<ii> vii;
typedef vector <vii> vvii;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector <ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vi nums(n);
    int flag = 1;
    for (int i = 0; i < n; ++i) {
        nums[i] = s[i] - '1';
        if (nums[i] == 1) flag = 0;
    }
    for (int j = 0; j < n; ++j) {
        if (nums[j] == 2) nums[j] = flag;
    }
    int ans = 0;
    for (int k = 0; k < n; ++k) {
        if (nums[k] && (((n-1)|k) == n-1)) ans++;
        if (ans == 2) ans = 0;
    }
    if (flag){
        if (ans) cout << "2\n";
        else cout << "0\n";
    }else{
        if (ans == 0) cout << "0\n";
        else cout << "1\n";
    }
}

