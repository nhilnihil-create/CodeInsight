#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
    ll n; cin >> n;

    vector<ll> plus;
    vector<ll> minus;

    rep(i, n){
        ll a; cin >> a;
        if(a >= 0) plus.push_back(a);
        else minus.push_back(a);
    }
    
    sort(plus.begin(), plus.end(), greater<>());
    sort(minus.begin(), minus.end());

    if(plus.size() == n){
        minus.push_back(plus.back());
        plus.pop_back();
    }else if(minus.size() == n){
        plus.push_back(minus.back());
        minus.pop_back();
    }
    ll cur = minus[0];
    vector<P> ans;
    for(int i = 0; i < plus.size() - 1; ++i){
        ans.push_back({cur, plus[i]});
        cur -= plus[i];
    }
    ans.push_back({plus[plus.size() - 1], cur});
    cur = plus[plus.size() - 1] - cur;

    for(int i = 1; i < minus.size(); ++i){
        ans.push_back({cur, minus[i]});
        cur -= minus[i];
    }

    cout << cur << endl;
    for(auto it : ans) cout << it.first << " " << it.second << endl;
    return 0;    
}