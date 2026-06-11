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

ll nC2(ll n){
    return n*(n-1)/2;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n), cnt(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll total = 0;
    for(int i = 0; i <= n; i++){
        total += nC2(cnt[i]);
    }
    for(int i = 0; i < n; i++){
        ll ans = total;
        ans -= nC2(cnt[a[i]]);
        ans += nC2(cnt[a[i]]-1);
        cout << ans << endl;
    }
    return 0;
}
