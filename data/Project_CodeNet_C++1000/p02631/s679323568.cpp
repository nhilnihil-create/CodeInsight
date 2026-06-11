#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define int long long

using namespace std;
const int inf = 1e18;
const double EPS = 0.00000001;
const int mod = 1000000007;

signed main(){
    int n;
    cin >> n;
    int mass[n];
    for(int i = 0;i<n;i++) cin >> mass[i];
    int c = 0;
    for(int i = 0;i<n;i++) c ^= mass[i];
    for(int i =0;i<n;i++){
        cout << (c^mass[i]) << " ";
    }
}
