#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int n;
    cin >> n;
    int left = n / 1.08;
    int right = (n+1) / 1.08;
    if (int(left*1.08) == n) cout << left << endl;
    else if (int(right*1.08) == n) cout << right << endl;
    else cout << ":(" << endl;
     
    return 0;
}