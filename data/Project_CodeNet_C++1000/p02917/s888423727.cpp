#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(INT_MAX);
    for(int i=0; i<n-1; ++i){
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(INT_MAX);

    ll ans=0;
    for(int i=0; i<(int)a.size()-1; ++i){
        ans += min(a[i], a[i+1]);
    }
    cout << ans;
}
