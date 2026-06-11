#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

long double a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    long double ans = 0, sum = 0;
    queue<long double> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++){
        long double x = (a[i] * (a[i] + 1) / 2);
        x = x / a[i];
        q.push(x);
        sum += x;
        ans += x;
    }
    for(int i = k; i < n; i++){
        long double x = (a[i] * (a[i] + 1) / 2);
        x = x / a[i];
        sum -= q.front();
        sum += x;
        q.pop();
        q.push(x);
        if(ans - sum < 1e-8) ans = sum;
    }
    cout << fixed << setprecision(8) << ans;

    return 0;
}


