#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int MAX=1e5+10;
const ll INF=1e18;
const double PI=acos(-1);


bool is_prime(ll n) {
    if (n==1) return false; 
    repr(i,2,int(sqrt(n)+1)) {
        if (n%i==0) return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);

    int x;
    cin >> x;
    while (1) {
        if (is_prime(x)) {
            cout << x << endl;
            break;
        }
        ++x;
    }

    return 0;   
}