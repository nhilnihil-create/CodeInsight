#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll> >;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

int main(){
    string s, s1, s2; ll n, res = 1;
    ll t1; char t2;
    cin >> s >> n;
    vector<ll> A(n);
    
    rep(i, n){
        cin >> A[i];
        if(A[i] == 2){
            cin >> t1 >> t2;
            if(res == 1){
                if(t1 == 1) s1.PB(t2);
                else s2.PB(t2);
            }
            else{
                if(t1 == 1) s2.PB(t2);
                else s1.PB(t2);
            }
        }
        else res *= -1;
    }

    if(res == -1) {
        reverse(ALL(s)); reverse(ALL(s2));
        cout << s2 << s << s1;
    }
    else{
        reverse(ALL(s1));
        cout << s1 << s << s2;
    }
    return 0;
}