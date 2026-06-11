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
#include <iomanip>
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    vector<ll> s(n+1);
    rep(i,n){
        s[i+1] += a[i];
        s[i+1] += s[i];
    }
    ll res = 0;
    res += p;
    for(int i=p;i<n;i++){
        if(a[p-1] > a[i]+m)break;
        ll T = p-1;
        T += n-i;
        ll hoge = v-T;
        if(hoge<=0){
            res++;
            continue;
        }
        // cerr << i << " " << hoge << " "<< m*hoge  << " " <<  (a[i]+m)*(i-p+1)   - (s[i]-s[p-1]) << endl;
        if(m*hoge - ( (a[i]+m)*(i-p+1)   - (s[i]-s[p-1]) ) <= 0){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}