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
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};




int main(){
    int n;cin >> n;
    vector<LL> a(n + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> a[i];
    }
    if(n == 0 && a[0] == 1){
        puts("1");
    }
    else if(a[0]){
        puts("-1");
    }
    else{
        vector<LL> as(n + 2, 0);
        for (int i = n + 1; i >= 1; i--) {
            as[i - 1] = as[i] + a[i - 1];
        }
        LL now = 1;
        LL ans = 1;
        for (int i = 1; i < n + 1; i++) {
            LL nnow = min(2 * now, as[i]);
            ans += nnow;
            nnow -= a[i];
            if(nnow < 0){
                puts("-1");
                return 0;
            }
            now = nnow;
        }
        if(now == 0){
            cout << ans << endl;
        }
        else{
            puts("-1");
        }
    }
    return 0;
}
