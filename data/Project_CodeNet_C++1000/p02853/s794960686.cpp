#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;
const ll p = 1e9+7;

int a, b;
int main(){
    #ifdef Irene
    freopen("in.txt", "r", stdin);
    #endif // Irene
    //ios_base::sync_with_stdio(false);

    map<int, int> mp;
    mp[1] = 300000;
    mp[2] = 200000;
    mp[3] = 100000;
    cin >> a >> b;
    cout << mp[a] + mp[b] + (a == 1 && b == 1 ? 400000 : 0) << "\n";
}
