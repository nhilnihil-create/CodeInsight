#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N-1);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    rep(i, N-1) cin >> c[i];

    int ans = 0;
    int pre_num = N+1;
    rep(i, N){
        int num = a[i]-1;
        ans += b[num];
        if(pre_num + 1 == num) ans += c[pre_num];
        pre_num = num;
    }
    cout << ans << endl;
    return 0;
}