#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> V;
typedef vector<vector<int>> Graph;

int main() {
    map<pair<int,int>,int> p;
    int n;
    cin >> n;
    rep(i,min(n,9)){
        p[make_pair(i+1,i+1)]++;
    }
    for(int i = 11 ;i<=n;i++){
        string s = to_string(i);
        p[make_pair(s[0]-'0',s[s.size()-1]-'0')]++;
    }
    ll ans = 0;
    for(int i =1;i<10;i++){
        for(int j =1;j<10;j++){
            ans += p[make_pair(i,j)]*p[make_pair(j,i)];
        }
    }
    cout << ans << endl;
}