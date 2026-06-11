#include <bits/stdc++.h>

#define ll long long
#define nums vector<int>
#define words vector<string>
#define letrs vector<char>
#define MOD 1000000007
#define pb push_back
#define llnums vector<ll>

using namespace std;

void solve() {

}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // A.cpp
    int n;
    cin >> n;
    set<string> d;
    string a;
    for (int i=0; i < n; i++) {
        cin >> a;
        d.insert(a);
    }
    cout << d.size() << '\n';
    return 0;
}

