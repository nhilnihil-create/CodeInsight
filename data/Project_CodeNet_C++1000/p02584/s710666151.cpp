#include<bits/stdc++.h> 
#define ll long long 
#define pb push_back 
#define vec vector<int> 
#define fo(i,n) for (ll i = 0; i < n; i++)
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second 
using namespace std;  
int main()
{ 
  ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
 
    ll a =min(K, X / D);
    K -=a;
    X -=a* D;
 
    if (K % 2 == 0) {
        cout << X << endl;
    } else {
        cout << D - X << endl;
    }
 
    return 0;
}