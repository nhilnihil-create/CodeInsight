#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};



int main(){
    LL k,q;cin >> k >> q;
    vector<LL> d(k);
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }
    while(q--){
        LL n,x,m;cin >> n >> x >> m;
        auto dd = d;
        LL S = 0;
        LL ans = n - 1;
        for (int i = 0; i < k; i++) {
            dd[i] %= m;
            if(dd[i] == 0) dd[i] = m;
            S += dd[i];
        }
        LL sum = x % m + (n - 1) / k * S;
        for (int i = 0; i < (n - 1 + k) % k; i++) {
            sum += dd[i];
        }
        ans -= sum / m;
        cout << ans << endl;
    }
    return 0;
}
