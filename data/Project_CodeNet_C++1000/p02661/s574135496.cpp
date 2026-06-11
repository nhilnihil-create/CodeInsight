#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll n;
    cin >> n;
    VL a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    ll up, bt;
    if(n % 2 == 0){
        bt = a[n/2-1] + a[n/2];
        up = b[n/2-1] + b[n/2];
    }else{
        bt = a[n/2];
        up = b[n/2];
    }
    cout << up - bt + 1 << endl;
    return 0;
}