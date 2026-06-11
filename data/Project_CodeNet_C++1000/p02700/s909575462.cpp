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
    int a,b,c,d, i=0;
    cin >> a >> b >> c >> d;
    while (a > 0 || c > 0) {
        if (i % 2 == 0) {
            c -= b;
            i++;
            if (c <= 0) break;
        }
        else {
            a -= d;
            i++;
            if (a <= 0) break;
        }
    }
    cout << ((a > c) ? "Yes\n" : "No\n");
    return 0;
}

