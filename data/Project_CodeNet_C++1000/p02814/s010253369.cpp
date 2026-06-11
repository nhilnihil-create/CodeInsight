#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

ll gcd(ll a, ll b){
    int r,temp;
    if (a < b){
        temp = a;
        a = b;
        b = temp;
    }
    while ( (r = a % b) != 0){
        a = b;
        b = r;
    }
    return b;
}

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    vector<ll> div_count_2(N,0);
    rep(i,N){
        ll A = vec[i];
        while(true){
            if (A % 2 == 1){
                break;
            }
            else{
                div_count_2[i]++;
                A /= 2;
            }
        }
    }
    bool possible = true;
    rep(i,N - 1){
        if (div_count_2[0] != div_count_2[i + 1]){
            possible = false;
        }
    }
    if (!possible) cout << 0 << endl;
    else{
        ll lcm = 1;
        rep(i,N){
            lcm = lcm * (vec[i] / 2) / gcd(lcm, (vec[i] / 2));
        }
        ll ans = M / lcm;
        if (ans % 2 == 1) cout << ans / 2 + 1 << endl;
        else cout << ans / 2 << endl;
    }
}

