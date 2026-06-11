#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    string s, t;
    cin >> s >> t;

    int ans = 0;
    rep(i, s.length()){
        if(s[i] != t[i]){
            ans ++;
        }
    }

    cout << ans << endl;

    return 0;
}