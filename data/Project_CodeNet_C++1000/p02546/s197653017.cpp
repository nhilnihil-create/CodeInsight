#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()

using namespace std;

int main() {
    nl // 

    // freopen("output.out", "w", stdout);

    string s;
    cin >> s;

    cout << (s.back() == 's' ? s + "es" : s+'s');

    return 0;
}