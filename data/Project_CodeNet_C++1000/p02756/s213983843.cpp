#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i < (int)(n); i++)
#define repd(i, n) for (int i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (int i = n-1; i >= (int)(k); i--)
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
//V,Pは大文字i,l,bは小文字
using ll = long long;
using Vi = vector<int>;
using VVi = vector<Vi>;
using Vl = vector<ll>;
using VVl = vector<Vl>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using P = pair<int,int>;
using Pll = pair<ll, ll>;
const ll mod = 1000000007;
const ll inf = 1000000000000;//10の12乗

int main() {
    string s;
    cin >> s;
    int n=s.size();
    int q;
    cin >> q;
    bool b=0;
    string sa,sb;
    rep(i,q){
        int x;
        cin >> x;
        if(x==1){
            b=(!b);
            continue;
        }
        int y;
        char c;
        cin >> y >> c;
        if(b){
            if(y==1) sb+=c;
            else sa+=c;
        }
        else{
            if(y==2) sb+=c;
            else sa+=c;
        }

    }
    reverse(all(sa));
    sa+=s;
    sa+=sb;
    if(b) reverse(all(sa));
    cout << sa << endl;
}