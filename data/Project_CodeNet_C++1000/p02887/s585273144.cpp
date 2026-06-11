#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
    int n;
    string s;
    cin >> n >> s;

    int cnt = 1;

    rep(i,n-1){
        char c1 = s[i];
        char c2 = s[i+1];
        if(c1 != c2) cnt++;
    }

    cout << cnt << endl;
    

    //cout << fixed << setprecision(6) << ans << endl;

    return 0;
    
}