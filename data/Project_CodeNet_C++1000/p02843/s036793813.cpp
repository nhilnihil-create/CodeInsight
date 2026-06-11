#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

int main(){
    int x; cin >> x;
    vector<bool> dp(x+1, false);
    dp[0] = true;
    for(int i = 1; i <= x; i++){
        int cnt = 0;
        while(cnt <= 5 && i-100-cnt >= 0){
            if(dp[i-100-cnt] == true) dp[i] = true;
            cnt++;
        }
    }
    // for(int i = 0; i <= x; i++) cout << dp[i] << endl;

    if(dp[x] == true) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
