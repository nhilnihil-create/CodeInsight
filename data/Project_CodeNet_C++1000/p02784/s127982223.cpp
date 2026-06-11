#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll H,N; cin >> H >> N;
    for(ll i=0; i<N; i++) {
        ll A; cin >> A;
        H-=A;
        if(H<=0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}