#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, b, ans = 0, temp, r=0;
    cin >> n >> a >> b;
    temp = n/(a+b);
    
    ans = temp*(a);
    r = (n-temp*(a+b));
    
    ans += min(r, a);
    cout << ans << endl;
    return 0;
}