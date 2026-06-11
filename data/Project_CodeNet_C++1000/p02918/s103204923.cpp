#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> Pair;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll INFL = 1e18;


int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int score = 0;
    rep(i,n-1){
        if(s[i]==s[i+1]) score++;
    }
    int ans = min(score+2*k,n-1);
    cout << ans << endl;
    return 0;
}