#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;


struct BIT{
    private:
    int n,n_;
    vector<long long> bit;

    public:
    BIT(int n):n(n){
        bit.resize(n+1);
        n_ = 1;
        while(n_<=n) n_<<=1;
        n_ >>= 1;
    }
    //1-index
    long long sum(int i){
        long long res = 0;
        while(i > 0){
            res += bit[i];
            i -= i&-i;
        }
        return res;
    }
    //1-index
    void add(int i,long long val){
        while(i <= n){
            bit[i] += val;
            i += i&-i;
        }
    }
    //return 1-index
    int lowerbound(long long w){
        if(w <= 0) return 0;
        int x = 0;
        for(int k=n_;k>0;k>>=1){
            if(x+k<=n&&bit[x+k]<w){
                w -= bit[x+k];
                x += k;
            }
        }
        return x+1;
    }
};

int main(){
    int n,q;
    cin >> n >> q;

    BIT bit(n);
    rep(i,n){
        int a;
        cin >> a;
        bit.add(i+1,a);
    }

    while(q--){
        int t;
        cin >> t;
        if(t==0){
            int p,x;
            cin >> p >> x;
            bit.add(p+1,x);
        }else{
            int l,r;
            cin >> l >> r;
            if(l==0) cout << bit.sum(r) << endl;
            else cout << bit.sum(r) - bit.sum(l) << endl;
        }
    }
    return 0;
}