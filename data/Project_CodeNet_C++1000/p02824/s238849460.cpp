#include<bits/stdc++.h>
#define N 5000000005
#define sag (root+root+1)
#define sol (root+root)
#define ort  ((bas+son)/2)
#define mod 1000000007

using namespace std;
typedef long long ll;

ll n, m, v, p;
ll arr[(ll)1e5+5];

bool check(ll ind) {
    ll sayi = arr[ind] + m;
    ll arttir = ind;
    ll sonlar = p-1;
    ll son_sayi = arr[n-p];
    if(son_sayi > sayi) return false;
    if(sonlar + arttir >= v) return true;
    ll oy_sayisi = m*v - (arttir + sonlar +1)*m;
    for(ll i = ind+1; i <= n-p; i++) {
        oy_sayisi -= (sayi - arr[i]);
        if(oy_sayisi <= 0) return true;
    }
    return false;
}
int main() {
    cin >> n >> m >> v >> p;
    //memset(arr, INT_MAX, sizeof arr);
    for(ll i = 0; i <n;i++) cin >> arr[i];
    sort(arr, arr+n);
    //for(int i=0; i<n; i++) cout << arr[i];
    ll l = 0, r = n-1;
    while(l < r-3) {
        ll mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    //cout << check(n-2) << endl;
    ll ans = n-1;
    for(ll i = l; i <= r; i++) {
        if(check(i)) {ans = i; break;}
    }
    cout << n - ans <<endl;
    

    return 0;
}