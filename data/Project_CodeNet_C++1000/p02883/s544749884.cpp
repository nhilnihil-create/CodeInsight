#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> A(n);
    vector<int> F(n);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> F[i];
    sort(A.begin(),A.end());
    sort(F.rbegin(),F.rend());
    ll l = -1,r = 1e12;
    while(l+1<r){
        ll mid = (l+r)/2;
        bool ok = [&](){
            ll s = 0;
            rep(i,n){
                s += max(0ll,A[i]-mid/F[i]);
            }
            return s <= k;
        }();
        if(ok) r = mid;else l = mid;
    }
    cout << r << endl;
    return 0;
}
