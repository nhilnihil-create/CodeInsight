#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    if (s.length() <= k) cout << s << endl;
    else cout << s.substr(0, k) << "..." << endl;
}