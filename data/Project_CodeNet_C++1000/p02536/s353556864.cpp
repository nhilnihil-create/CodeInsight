#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}

const int MAX_N = 200100;
int par[MAX_N]; // 親
int rank_[MAX_N]; // 木の深さ
int cnt_[MAX_N]; // 属する頂点の個数(親のみ正しい)

// n要素で初期化
void UFinit(){
    for(int i=0;i<MAX_N;i++){
        par[i] = i;
        rank_[i] = 0;
        cnt_[i] = 1;
    }
}

// 木の根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank_[x] < rank_[y]){
        par[x] = y;
        cnt_[y] += cnt_[x];
    }else{
        par[y] = x;
        cnt_[x] += cnt_[y];
        if(rank_[x] == rank_[y]) rank_[x]++;
    }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y){
    return find(x) == find(y);
}


int main() {
    UFinit();
    int n, m;
    cin >> n >> m;

    int ans = n-1;

    rep(i,m){
        int a, b;
        cin >> a >> b;
        if(same(a,b));
        else{
            ans--;
            unite(a,b);
        }
    }

    cout << ans << endl;
    return 0;
}

