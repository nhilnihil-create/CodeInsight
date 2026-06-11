#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;


#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORDOWN(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define ff first
#define ss second
//mt19937 rnd(150);



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //  freopen("goat5.in", "r", stdin);
    //  freopen("goat5.out","w", stdout);

    string s;
    cin >> s;

    int sum = 0;

    for (int i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
    }

    if (sum % 9 == 0)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
