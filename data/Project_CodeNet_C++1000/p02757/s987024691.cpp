#include <bits/stdc++.h>
#define rep(i,n)  for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define deb(x) cerr << #x <<": " << x << '\n';
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long double ld;
typedef long long ll;

int main(){
    ios;
    ll N, P; cin >> N >> P;
    string S; cin >> S;
    ll ans = 0;
    if(P == 2 || P == 5){
        rep(i,N){
            if( (S[i] - '0') % P == 0 ) ans += i + 1;
        }
    }
    else{
        unordered_map<ll,ll>Remainders;
        Remainders[0] = 1;
        ll _10Power = 1, number = 0, remainder;
        
        for(ll i = S.size() - 1; ~i; --i){
            number += (S[i] - '0') * _10Power;
            remainder = number % P;
            ++Remainders[remainder];
            _10Power *= 10;
            _10Power %= P; number %= P;
        }
        for(auto rem : Remainders){
        ans += (rem.second * (rem.second - 1)) / 2;
        }
    }
    cout << ans;
    return 0;
}
