#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const ll inf = 1e18+7;
const int N = 1e6+9;

int main() {
    ios_base::sync_with_stdio(0);
    ll a,b,c,d;
    ll A[5];
    cin>>A[0]>>A[1]>>A[2]>>A[3];
    ll mx=-inf;
    for(int i=0;i<2;++i) {
        for(int j=2;j<4;++j) {
            ll tmp = A[i]*A[j];
            mx = max(mx, tmp);
        }
    }
    cout<<mx<<endl;
    return 0;
}