#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    ve<int> l(k),r(k);
    int i = 0, cnt = 0;
    while(i<n){
        if(s[i] == 'o'){
            l[cnt] = i;
            cnt++;
            i += c;
            if(cnt == k) break;
        }
        i++;
    }
    i = 0, cnt = 0;
    reverse(s.begin(), s.end());
    while(i<n){
        if(s[i] == 'o'){
            r[k-cnt-1] = n-1-i;
            cnt++;
            i += c;
            if(cnt == k) break;
        }
        i++;
    }
    rep(i,k){
        if(l[i] == r[i]) cout << r[i]+1 << endl;
    }
    return 0;
}