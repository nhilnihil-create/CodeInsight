#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const ll INF=2e15;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    rep(i,n-1) {
        repr(j,i+1,n) {
            bitset<10> biti(i),bitj(j);
            rep(l,10) {
                if (biti[l]!=bitj[l]) {
                    cout << l+1 << ' ';
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
