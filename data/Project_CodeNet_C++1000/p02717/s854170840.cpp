#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (2147483647)
#define MOD (int)(998244353) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, z;
    cin >> x >> y >> z;
    swap(x, y);
    swap(x, z);
    cout << x << ' ' << y << ' ' << z << '\n';
    return 0;
}