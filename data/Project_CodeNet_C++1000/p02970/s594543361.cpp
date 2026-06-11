#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,d;
    cin >> n >> d;
    int see_n = 2*d+1;
    int ans = n % see_n == 0 ? n / see_n : n / see_n + 1;
    cout << ans << endl;
}