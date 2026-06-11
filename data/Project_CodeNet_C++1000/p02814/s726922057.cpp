#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> init(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

int n, m;
vector<int> a;

ll lcm(int a, int b){
    return (ll)a*b/__gcd(a, b);
}

int numTwos(int a){
    int ans = 0;
    while(a%2==0){
        a /= 2;
        ++ans;
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    a = vector<int>(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] /= 2;
    }

    ll lowest = a[0];
    int twos = numTwos(a[0]);
    for(int i = 1; i < n; ++i){
        lowest = lcm(lowest, a[i]);
        if(lowest > m || numTwos(a[i]) != twos){
            cout << "0\n";
            return;
        }
    }

    ll ans = 1 + (m - lowest)/(2LL*lowest);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}