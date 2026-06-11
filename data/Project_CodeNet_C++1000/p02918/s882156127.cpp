#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int ans = 0,cnt = 0;
    rep(i,n-1){
        if(s[i]==s[i+1])ans++;
        else cnt++;
    }
    if(2*k<cnt) cout << ans + 2*k << endl;
    else cout << ans + cnt << endl;
    return 0;
}