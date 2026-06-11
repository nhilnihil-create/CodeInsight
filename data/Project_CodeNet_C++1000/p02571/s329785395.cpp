#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
#define rep(i, n)  for (int i = 0; i <  (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ll INF = ll(1e18)+1;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s,t;
    cin >> s >> t;

    ll result = INF;
    ll count;
    rep(i,s.size()-t.size()+1){
        count = 0;
        rep(j,t.size()){
            if(s[i+j] != t[j]) count++;
        }
        result = min(result,count);
    }
    
    cout << result;
}