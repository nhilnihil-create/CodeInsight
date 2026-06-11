#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;

 ll calC(ll a, ll b){

     if(a == 1) return 0;
     ll ans = 1;
    ll tmpB = b;
    ll tmpA = a;
    for(int i = 1; i <= b; i ++){
         ans *= tmpA;
         tmpA --;
     }
     for(int i = 1; i <= b; i ++){
         ans /= tmpB;
         tmpB --;
     }

    return ans;
}
int main() {
    ll n; cin >> n;
    ll ans = 0;
    ll count = 1;
    string prev = "",cur;
    vector<string> s(n);
    vector<string> S(n);
    rep(i,n) {
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
        S[i] = s[i];
    }
    sort(S.begin(),S.end());


    prev = S[0];
    for(int i = 1; i < n; i ++){
        cur = S[i];
        if(prev != cur){
            ans += calC(count,2);
            count = 1;
        }else{
            count ++;
        }
        prev = cur;
    }

    ans += calC(count,2);
    count = 0;

    cout << ans;

    return 0;
}