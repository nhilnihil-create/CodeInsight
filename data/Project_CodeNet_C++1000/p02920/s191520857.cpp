#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    int N;
    cin >> N;
    ll e[N+1];
    e[0] = 1;
    rep(i, N) e[i+1] = 2*e[i];
    ll S;
    map<ll, ll> mp;
    rep(i, e[N]){
        cin >> S;
        if(mp.count(S)) mp[S]++;
        else mp[S] = 1;
    }
    vector<ll> vec;
    map<ll, ll>::iterator ite;;
    ite = mp.end();
    ll tmp;
    ite--;
    tmp = ite->first;
    vec.push_back(tmp);
    mp[tmp]--;
    if(mp[tmp] == 0) mp.erase(tmp);
    rep(i, N){
        rep(j, e[i]){
            ll k = vec[j];
            if(!mp.count(k)) mp[k] = 0;
            ite = mp.find(k);
            if(ite == mp.begin()){
                cout << "No" << endl;
                exit(0);
            }
            ite--;
            tmp = ite->first;
            vec.push_back(tmp);
            mp[tmp]--;
            if(mp[tmp] == 0) mp.erase(tmp);
            if(mp[k] == 0) mp.erase(k);
        }
    }
    cout << "Yes" << endl;
}