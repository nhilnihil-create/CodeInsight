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
int lcm(int a, int b){return a*b / gcd(a, b);}

int main(){
    int n;
    cin >> n;
    vector<ll> a(n), sum(n+1); //n番目までの累積和
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        sum[i+1] = sum[i]+a[i];
    }
    ll ans = 20202020202020;
    for(int i = 1; i < n; i++){
        ll low = sum[i];
        ll high = sum[n]-sum[i];
        ans = min(ans, abs(low-high));
    }
    cout << ans << endl;
    return 0;
}
