#include <bits/stdc++.h>
#define MAXN 200010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e18 + 7;


int main (){
    ios_base::sync_with_stdio(false);
    int x, a;
    cin >> x >> a;

    cout << (x < a? "0": "10") << endl;

    return 0;
}