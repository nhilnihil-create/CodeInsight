#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    sort(all(vec));
    bool ans = true;
    if (N % 3 != 0){
        rep(i,N){
            if (vec[i] != 0) ans = false;
        }
    }
    else{
        ll small;
        ll middle;
        ll large;
        small = vec[0];
        middle = vec[N / 3];
        large = vec[(N / 3) * 2];
        rep(i,N / 3){
            if (vec[i] != small) ans = false;
            if (vec[(N / 3) + i] != middle) ans = false;
            if (vec[(N / 3) * 2 + i] != large) ans = false;
        }
        if ((small ^ middle) != large) ans = false;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
