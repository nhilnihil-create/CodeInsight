#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, K, ans=0, tmp=0;
vector<ll> A, F;

signed main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        F.push_back(a);
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());
    ll ok=pow(10,12)+5;
    ll ng=-1;
    while(ng+1!=ok) {
        ll l = K;
        ll mid = (ok+ng)/2;
        for(int i=0;i<N;i++) {
            //cout << A[i] << " : "  << A[i]-mid/F[i] << endl;
            //l-=max(0LL,A[i]-mid/F[i]);
            if(A[i]>mid/F[i]) {
                l -= (A[i]-mid/F[i]);
            }
        }
        if(l>=0) ok = mid;
        else ng = mid;
        //cout << ok << " : " << ng << " : " << l << endl;
    }
    cout << ok << endl;
    return 0;
}