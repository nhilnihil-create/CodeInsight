#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
struct edge{ll to, cost;};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define INF 1000000000000
#define ALL(a)  (a).begin(),(a).end()
#define large 1000000000000000000
std::map<char,int> janken;

int main(){
    ll n,k;
    cin >> n >> k;
    ll r,s,p;
    cin >> r >> s >> p;
    janken['r'] = p;
    janken['s'] = r;
    janken['p'] = s;
    string t;
    cin >> t;
    ll sum = 0;
    bool seen[n];
    for(int i = 0; i < n; i++){
        seen[i] = false;
    }
    for(int i = 0; i < n; i++){
        if(i < k){
            sum += janken[t[i]];
        }
        else{
            if(t[i] != t[i-k]){
                sum += janken[t[i]];
            }
            else if(t[i] == t[i-k] && seen[i-k]){
                sum += janken[t[i]];
            }
            else{
                seen[i] = true;
            }
        }
    }
    cout << sum << endl;

}