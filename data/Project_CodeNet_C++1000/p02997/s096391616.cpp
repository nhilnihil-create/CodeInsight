#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, K, ans=0, tmp=0;
vector<ll> A(MAXN, 0);

signed main(){
    cin >> N >> K;
    if(K>(N-1)*(N-2)/2) {
        cout << -1 << endl;
        return 0;
    }
    else {
        cout << N-1+(N-1)*(N-2)/2-K << endl;
        for(int i=2;i<=N;i++) {
            cout << 1 << " " << i << endl;
        }
        ll i = 2;
        ll j = 2;
        ll ct=0;
        while(ct!=(N-1)*(N-2)/2-K) {
            ct++;
            if(j==N) {
                i++;
                j = i+1;
            }
            else {
                j++;
            }
            cout << i << " " << j << endl;
        }
    }
    return 0;
}