#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,m;
    cin >> n >> m;
    int ans1 =0,ans2 = 0;
    if(n > 1) ans1 = n * (n-1)/2;
    if(m > 1) ans2 = m * (m-1)/2;
    cout << ans1 + ans2 << endl;
}