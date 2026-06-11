#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    sort(all(a));
    vector<ll>s(n);
    for(int i=0;i<n;i++){
        s[i] += a[i];
        if(i!=0)s[i] += s[i-1];
    }
    ll t = a[n-p];
    int res = 0;
    for(int i=0;i<n;i++){
        if(a[i]+m<t)continue;
        if(i>=n-p){
            res++;
            continue;
        }
        ll T = a[i]+m;
        ll id = n-p;
        ll pid = upper_bound(all(a),a[i])-a.begin();
        pid--;
        ll tmp = 0;
        tmp += (pid+1) * m;
        if(pid!=0)tmp += T*(id-pid+1) - (s[id]-s[pid-1]);
        else tmp += T*(id-pid+1) - (s[id]);
        // cerr << i << " " << T << " " << pid << " " << id << " " << tmp << " " << m*v << endl;
        if(tmp >= m*(v-p+2)){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}