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
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    int sum=(n-1)*(n-2)/2;
    if (k>sum) {
        cout << -1 << endl;
    } else {
        cout << n-1+sum-k << endl;
        repr(i,2,n+1) cout << 1 << ' ' << i << endl;
        int cnt=0;
        bool flag=0;
        repr(i,2,n) {
            repr(j,i+1,n+1) {
                if (cnt>=sum-k) {
                    flag=1;
                    break;
                }
                cout << i << ' ' << j << endl;
                ++cnt;
            }
            if (flag) break;
        }
    }
        
    
    return 0;   
}