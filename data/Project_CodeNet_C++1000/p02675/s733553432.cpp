#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    int a = n % 10;
    if (a == 2 || a == 4 || a == 5 || a == 7 || a == 9) cout << "hon" << endl;
    else if (a == 0 || a == 1 || a == 6 || a == 8) cout << "pon" << endl;
    else cout << "bon" << endl;
}