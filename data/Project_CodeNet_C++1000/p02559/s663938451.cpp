#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    fenwick_tree<ll> ft(n);
    rep(i,n){
        int a;
        cin >> a;
        ft.add(i,a);
    }
    rep(i,q){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==1){
            cout << ft.sum(u,v) << "\n";
        }else{
            ft.add(u,v);
        }
    }
    return 0;
}