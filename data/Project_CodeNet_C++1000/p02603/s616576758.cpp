#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const ll MOD=1000000007;
const ll LINF=1ll<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};





int main(){
    int n;cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll now = 1000, t = 0;
    for (int i = 1; i < n; i++) {
        if(a[i - 1] < a[i]){
            t = now / a[i - 1];
            now += (a[i] - a[i - 1]) * t;
        }
    }
    cout << now << endl;
    return 0;
}


