#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
int k,q;
typedef long long ll;
ll d[5001];
ll n[5001];
ll x[5001];
ll m[5001];

int main(){
    cin >> k >> q;
    for (int i=0;i<k;i++){
        cin >> d[i];
    }
    for (int i=0;i<q;i++){
        cin >> n[i] >> x[i] >> m[i];
    }
    for (int i=0;i<q;i++){
        ll dd[5001];
        ll l,p;
        l = (n[i]-1)/k;
        p = (n[i]-1) % k;
        ll sum=0;
        ll sumb=0;
        ll cnt=0;
        ll cntb=0;
        x[i] %= m[i];
        for (int j = 0;j<p;j++){
            dd[j] = d[j] % m[i];
            sum += dd[j];
            sumb += dd[j];
            if (dd[j] == 0){
                cnt += 1;
                cntb += 1;
            }
        }
        for (ll j = p;j<k;j++){
            dd[j] = d[j] % m[i];
            x[i] %= m[i];
            sum += dd[j];
            if (dd[j] == 0){
                cnt += 1;
            }
        }
        sum = sum * l + sumb + x[i];
        cnt = cnt * l + cntb;
        ll ans=0;
        ans = n[i] -1 -sum/m[i]-cnt;
        cout << ans << endl;
    }
    
}

