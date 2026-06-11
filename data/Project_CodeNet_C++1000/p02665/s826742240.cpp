#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100005];
long long ruia[100006];
long long ans = 0;
long long nowleef = 1;
int main(){
    cin >> n;
    for(long long i = 0;i<n+1;i++){
        cin >> a[i];
    }
    for(long long i = 0;i<n+1;i++){
        ruia[n-i] = ruia[n-i+1] + a[n-i];
    }
    for(long long i = 0;i<n+1;i++){
        if(nowleef>ruia[i]){
            ans = -1;
            break;
        }
        ans += nowleef;
        if(nowleef<a[i]){
            ans = -1;
            break;
        }
        nowleef -= a[i];
        nowleef = min(nowleef*2LL,ruia[i+1]);
    }
    cout << ans << endl;
    return 0;
}