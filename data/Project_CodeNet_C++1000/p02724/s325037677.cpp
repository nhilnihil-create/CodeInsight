#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

int main(){
    int n; cin >> n;
    cout << n / 500 * 1000 + (n % 500) / 5 * 5 << endl;
}