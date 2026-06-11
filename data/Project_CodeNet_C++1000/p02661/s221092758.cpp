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
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,-1,-1,1,1};



int main(){
    int n;cin >> n;
    vector<LL> a(n),b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(ALL(a));
    sort(ALL(b));
    if(n%2 == 1){
        cout << (b[n/2] - a[n/2] + 1) << endl;
    }
    else{
        LL la = a[(n - 1) / 2], ra = a[n / 2];
        LL lb = b[(n - 1) / 2], rb = b[n / 2];
        LL ans = (rb + lb) - (ra + la);
        cout << ans + 1 << endl;
    }
    return 0;
}
