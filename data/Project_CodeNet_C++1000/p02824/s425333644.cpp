#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ng = -1;
    ll ok = n;
    while(ok - ng > 1){
        ll mid = (ok + ng)/2;
        ll limit = a[mid] + m;
        if(limit < a[n-p]){
            ng = mid;
            continue;
        }
        ll sum = m + (p-1)*m + (mid)*m;
        for(int i = mid+1 ; i <= n-p; i++){
            sum += limit - a[i];
        }
        if(sum < m*v){
            ng = mid;
        }
        else{
            ok = mid;
        }
    }
    cout << n - ok << endl;
}