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
    LL n,k;cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        vector<LL> b(n + 1, 0);
        for (int j = 0; j < n; j++) {
            LL l = max(0LL, j - a[j]);
            LL r = min(n, j + a[j] + 1);
            b[l]++;
            b[r]--;
        }
        for (int j = 0; j < n; j++) {
            b[j + 1] += b[j];
        }
        vector<LL> na(n);
        for (int i = 0; i < n; i++) {
            na[i] = b[i];
        }
        if(na == a) break;
        a = na;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i + 1 == n ? "\n": " ");
    }
    return 0;
}
