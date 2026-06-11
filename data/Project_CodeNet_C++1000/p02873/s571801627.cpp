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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n+1);

    for(int i=0; i<n; ++i)
        if(s[i]=='<')
            a[i+1] = a[i]+1;
    
    for(int i=n-1; i>=0; --i)
        if(s[i]=='>')
            a[i] = max(a[i], a[i+1]+1);
    
    ll ans=0;
    for(auto x:a)
        ans += x;
    
    cout << ans;
}