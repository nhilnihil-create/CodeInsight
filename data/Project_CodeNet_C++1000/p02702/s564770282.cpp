#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll mod = 2019;
int main(){
    string S; cin >> S;
    ll N = S.size();

    ll val = 0;
    ll pm = 1;
    vector<int> m(2030,0);
    m[0]++;
    ll res = 0;
    for(int i=N-1;i>=0;i--){
        val = val + pm * (S[i]-'0');
        val %= mod;
        pm = (pm * 10) % mod;
        res += m[val];
        m[val]++;
    }

    cout << res << endl;
}