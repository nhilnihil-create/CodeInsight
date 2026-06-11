#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
const ll MOD = 1e9 + 7;


int mainsolve(){

    ll n,k,c;
    cin >> n >> k >> c;

    string s;
    cin >> s;

    vector<ll> tmp1, tmp2, res;

    rep(i,n){
        if(!tmp1.empty() && i - tmp1.back() <= c) continue;
        if(s[i] == 'o') tmp1.push_back(i);
        if(tmp1.size() == k) break;
    }

    for(ll i = n-1; i >= 0; i--){
        if(!tmp2.empty() && tmp2.back() - i <= c) continue;
        if(s[i] == 'o') tmp2.push_back(i);
        if(tmp2.size() == k) break;        
    }

    rep(i,k){
        if(tmp1[i] == tmp2[k-1-i]){
            cout << tmp1[i]+1 << endl;
        }
    }

	return 0;
}

int main(){
	
	return mainsolve();

}