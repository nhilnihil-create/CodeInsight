#include<bits/stdc++.h>
/* #define int long long */
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    int n;
    cin >> n;
    set<string> s;
    int ans = 0;
    rep(i, n){
        string tmp;
        cin >> tmp;
        auto itr = s.find(tmp);
        if(itr == s.end()){
            ans++;
            s.insert(tmp);
        }
    }
    cout << ans << endl;

}