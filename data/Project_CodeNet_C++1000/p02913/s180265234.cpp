#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll n, k;
vector<int> order;
vector<int> sa;
vector<int> lcp;

// (order[i], order[i + k])と(order[j], order[j + k])を比較.
bool compare_sa(int i, int j){
    if(order[i] != order[j]) return order[i] < order[j];
    else {
        int ri = (i + k <= n) ? order[i + k] : -1;
        int rj = (j + k <= n) ? order[j + k] : -1;
        return ri < rj;
    }
}

//文字列Sの接尾辞配列を構築 (O(n*logn*logn))
void construct_sa(string S){
    n = S.length();
    sa.resize(n+1);
    order.resize(n+1);
    vector<ll> tmp(n+1);
    
    //最初の1文字. ランクを文字コードで表現
    for(int i = 0; i <= n; i++){
        sa[i] = i;
        order[i] = (i < n) ? S[i] : -1;
    }

    //k文字についてソートされているところから、2k文字でソートする
    for(k = 1; k <= n; k *= 2){
        sort(sa.begin(), sa.end(), compare_sa);

        //tmpに次のランクを格納. 辞書順にランク計算.
        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++){
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
        }
        for(int i = 0; i <= n; i++){
            order[i] = tmp[i];
        }
    }
}

// 文字列Sとその接尾辞配列saを受け取り、高さ配列lcpを返す. (O(n))
void construct_lcp(string S){
    n = S.length();
    lcp.resize(n);
    order.resize(n+1);

    for(int i = 0; i <= n; i++)
        order[sa[i]] = i;

    int h = 0;
    lcp[0] = 0;
    for(int i = 0; i < n; i++){
        // 文字列中での位置iの接尾辞と、接尾辞配列中でその一つ前の設備時のLCPを求める.
        int j = sa[order[i] - 1];

        // hを先頭の分1減らし、後ろが一致しているだけ増やす.
        if(h > 0) h--;
        for(; j + h < n && i + h < n; h++){
            if(S[j + h] != S[i + h]) break;
        }

        lcp[order[i] - 1] = h;
    }
}

const int INF = 10000000;
class SegmentTree{
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v){
        int size = v.size();
        n = 1;
        while(n < size) n *= 2;
        node.resize(2*n-1, INF);

        for(int i = 0; i < size; i++){
            node[n-1+i] = v[i];
        }
        for(int i = n-2; i >= 0; i--){
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }

    void update(int idx, int val){
        idx += n-1;
        node[idx] = val;
        while(idx > 0){
            idx = (idx-1)/2;
            node[idx] = min(node[2*idx+1], node[2*idx+2]);
        }
    }

    //return min value within [a,b)
    //call get_min(a, b);
    int get_min(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;

        if(b <= l || r <= a) return INF;

        if(a <= l && r <= b) return node[k];

        int vl = get_min(a, b, 2*k+1, l, (l+r)/2);
        int vr = get_min(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 0;

    construct_sa(S);
    construct_lcp(S);

    vector<int> tmp(N);
    REP(i,N){
        tmp[i] = lcp[sa[i+1]];
    }

    SegmentTree stree(lcp);
    //SegmentTree stree(tmp);

    REP(i,N){
        REPi(j,i+1,N+1){
            int x, y;
            //ll l = lcp[i];
            //int l = stree.get_min(i, j+1);
            x = sa[i], y = sa[j];
            if(x > y) swap(x, y);
            int l = stree.get_min(i, j);
            //printf("(%d, %d), (%d, %d): %d\n", i, j, x, y, l);
            //ll a = sa[i];
            //ll b = sa[j];
            //if(abs(b-a) < l) continue;
            //chmin(l, j-i);
            chmin(l, y - x);
            //if(y-x < l) continue;
            chmax(ans, l);
        }
    }

    cout << ans << endl;
    return 0;
}
