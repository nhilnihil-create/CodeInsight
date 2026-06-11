#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    ll a,b,c;
    cin >> a >> b >> c;

    bool ans = (4*a*b<(c-a-b)*(c-a-b));
    ans = (ans&&(c>a+b));
    cout << ((ans)?"Yes":"No") << endl;
    
}