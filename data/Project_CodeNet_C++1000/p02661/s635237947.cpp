#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n){
        cin >> a.at(i) >> b.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n%2==0){
        ll mi = a.at(n/2-1) + a.at(n/2);
        ll ma = b.at(n/2-1) + b.at(n/2);
        cout << ma - mi + 1 << endl;
    }
    else{
        ll mi = a.at(n/2);
        ll ma = b.at(n/2);
        cout << ma - mi + 1 << endl;
    }
    return 0;
}
