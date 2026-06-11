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
    dsu uf(n);
    rep(i,q){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==0){
            uf.merge(u,v);
        }else{
            cout << uf.same(u,v) << "\n";
        }
    }
    return 0;
}