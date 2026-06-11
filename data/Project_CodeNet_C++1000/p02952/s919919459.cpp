#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int i=1; i<=N; ++i){
        int n = to_string(i).length();
        if(n%2) ans++;
    }
    cout << ans << endl;
    return 0;
}
