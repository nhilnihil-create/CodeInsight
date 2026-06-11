#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
typedef pair<int,int> pii;

ll C2(ll k){
    ll cnt = 0;
    while(k % 2 == 0){
        cnt++;
        k /= 2;
    }
    return cnt;
}

map<long long, int> prime_factor(long long n){
    map< long long, int> ret;

    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            ret[i]++;
            n /= i;
        }
    }

    if( n != 1) ret[n] = 1;
    return ret;
}

int main(){
    ll N, M; cin >> N >> M;
    vector<ll > A(N);
    rep(i, 0, N) cin >> A[i];
    int x = 0;
    
    rep(i, 0, N){
        if(i == 0) x = C2(A[i]);
        else{
            if(x != C2(A[i])){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    
    map<ll, int> mp;
    ll lcm = 1;
    lcm = A[0];
    rep(i, 1, N){
        lcm = lcm * A[i] / __gcd(lcm, A[i]);
    }
    lcm /= 2;
    //cout << lcm << endl;
    cout << M  / lcm  - M / (lcm * 2) << endl;

    


}
