#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    SPEED;
    int n;
    cin >> n;
    int fh = n/500;
    n%=500;
    int fv = n/5;
    cout << 1000*fh + fv*5 << endl;
    return 0;
}