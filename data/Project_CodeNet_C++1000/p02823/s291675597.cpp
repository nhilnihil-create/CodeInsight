#include <bits/stdc++.h>
#define rep(i,n) for(int i = 1;i < (n)+1;i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll s = b-a;
    if(s%2 == 0) cout << s/2 << endl;
    else cout << min(n-b,a-1) + 1 + (s-1)/2 << endl;
}
