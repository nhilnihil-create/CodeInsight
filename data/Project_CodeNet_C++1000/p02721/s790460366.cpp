typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,k,c;
    std::cin >> n>>k>>c;
    
    string s;
    std::cin >> s;
    vector<ll> l(n,-1),r(n,-1);
    ll last = -1e15;
    ll now = 0;
    for (ll i = 0; i < n; i++) {
        if(now==k)break;
        if(s[i]=='o'&&last+c<i){
            l[i] = now;
            last = i;
            now++;
        }
    }
    now = k-1;
    last = -1e15;
    for (ll i = 0; i < n; i++) {
        if(s[n-1-i]=='o'&&last+c<i){
            r[n-1-i] = now;
            last = i;
            now--;
        }
    }
    
    for (int i = 0; i < n; i++) {
        // std::cout << l[i] <<" "<<r[i] << std::endl;
        if(r[i]!=-1&&r[i]==l[i]){
            std::cout << i+1 << std::endl;
        }
    }
}
