#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll x;
    cin >> x;
    ll a, b;
    for(a = -3000;a < 3000; a++){
        for(b = -3000; b < 3000;b++){
            if(a*a*a*a*a-b*b*b*b*b==x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    return 0;
}
