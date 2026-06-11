#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for(int i=0; i<(n); ++i)

int main(void){
    int n, m;
    int a[101], b[101];
    bool flag;
    while(cin >> n >> m && n) {
        rep(i, n) scanf("%d", &a[i]);
        rep(i, m) scanf("%d", &b[i]);
        int suma = 0, sumb = 0;
        rep(i, n) suma += a[i];
        rep(i, m) sumb += b[i];
        flag = false;
        int ans_a = INT_MAX/2, ans_b = INT_MAX/2;
        rep(i, n) {
            rep(j, m) {
                if(suma-sumb == 2*(a[i]-b[j])) {
                    if(ans_a+ans_b > a[i]+b[j]) {
                        ans_a = a[i];
                        ans_b = b[j];
                        flag = true;
                    }
                }
            }
        }
        if(flag) cout << ans_a << " " << ans_b << endl;
        else cout << -1 << endl;
    }
}