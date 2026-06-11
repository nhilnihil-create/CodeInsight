#include<iostream>
#include<algorithm>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)

long int n, m, v, p;
long int a[100000];
// 初期状態でp番目の要素のindex
long int mn;
// 上位i個の累積和
long int sm[100001];

bool C(long int x){
    long int poi = v - (p - 1) - (n - (x + 1)) - 1;
    

    long int dif;
    dif = sm[x] - sm[mn] - a[x] * (x - mn);
    long int imp = (x - mn) - poi;
    // cout << x << " " << poi << " " << imp << " " << dif << endl;
    if (a[x] == a[mn]){
        return true;
    }
    if (a[mn] - a[x] > m){
        return false;
    }
    if (poi <= 0){
        return true;
    }
    if (dif > imp * m){
        return false;
    }else{
        return true;
    }
}

int main(){
    cin >> n >> m >> v >> p;
    rep(i, n) cin >> a[i];
    sort(a, a + n, greater<long int>());
    sm[0] = 0;
    for (int i = 0; i < n; i++){
        sm[i+1] = sm[i] + a[i];
    }
    mn = p - 1;
    long int l = mn;
    long int r = n - 1;
    while(l < r - 1){
        long int mid = (l + r) / 2;
        if (C(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    long int ans;
    if (C(r)){
        ans = r + 1;
    }else{
        ans = l + 1;
    }
    // rep(i, n) cout << a[i] << " ";
    // cout << endl;
    // rep(i, n + 1) cout << sm[i] << " ";
    // cout << endl;
    // cout << l << " " << r << endl;
    cout << ans << endl;
}