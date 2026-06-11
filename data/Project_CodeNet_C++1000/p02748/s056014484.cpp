#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll A, B, M, ans = 2*pow(10,5);
    cin >> A >> B >> M;
    vector<ll> a(A+1), b(B+1), c(M+1), x(M+1), y(M+1);
    for(int i = 1; i <= A; ++i) cin >> a[i];
    for(int i = 1; i <= B; ++i) cin >> b[i];
    for(int i = 1; i <= M; ++i) cin >> x[i] >> y[i] >> c[i];
    for(int i = 1; i <= M; ++i){
        ans = min(ans, a[x[i]]+b[y[i]]-c[i]);
    }
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());
    ans = min(ans, a[1] + b[1]);
    cout << ans << endl;
    return 0;
}