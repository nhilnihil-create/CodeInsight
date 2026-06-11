
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i,n-1) cin >> b[i];

    vector<int> a(n);
    a[0] = b[0];
    for(int i=1; i<n-1; i++){
        a[i] = min(b[i],b[i-1]);
    }
    a[n-1] = b[n-2];

    ll sum=0;
    rep(i,n){
        sum += a[i];
    }
    cout << sum << endl;

}