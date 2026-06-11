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
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int t=1, ans=0;
    for(int i=0; i<n; ++i){
        if(a[i]==t){
            ans++;
            ++t;
        }
    }

    if(ans==0)
        cout << -1;
    else
        cout << n-ans;
    return 0;
}
