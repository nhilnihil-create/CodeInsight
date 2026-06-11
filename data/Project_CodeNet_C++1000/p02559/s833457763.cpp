#include <bits/stdc++.h>
using namespace std;

typedef long long SEGNODE_TYPE;   // セグ木のノードの型の定義
class Segtree
{
    public:

    SEGNODE_TYPE monoid;
    int segsize;    // セグ木の大きさ
    vector<SEGNODE_TYPE> value;

    // [引数]
    //          int n                   : 大きさ
    //          SEGNODE_TYPE start      : 初期値
    //          SEGNODE_TYPE mnd        : 単位元（モノイド）
    // [動作]
    //          セグ木を作る
    // ※SEGNODE_TYPE の定義を忘れずに
    Segtree() {}
    Segtree(int n, SEGNODE_TYPE start, SEGNODE_TYPE mnd) {    
        segsize = 1;
        while(segsize < n){
            segsize = segsize * 2;
        }
  
        value = vector<SEGNODE_TYPE>(2 * segsize - 1, start);
        monoid = mnd;
    }      

    // [引数]
    //          int i           : 変更箇所
    //          SEGNODE_TYPE x  : 変更値
    // [動作]
    //          場所iをxに変更
    void UpDate(int i, SEGNODE_TYPE x) {
        i += segsize - 1;
        value[i] = x;
  
        while(i > 0){
            i = (i-1) / 2;
            value[i] = Requirement(value[i * 2 + 1], value[i * 2 + 2]);
        }

        return;
    }

    // [引数]
    //          int a   : 区間の左端
    //          int b   : 区間の右端
    //          int n   : 全区間の幅
    // [動作]
    //          区間[a, b)のクエリを処理する（SegQueryへ橋渡し）
    // ※呼び出す際にはSEGNODE_TYPE Requirement(SEGNODE_TYPE x, SEGNODE_TYPE y)の中身を確認
    SEGNODE_TYPE Query(int a, int b, int n) {
        return ( SegQuery(a, b+1, 0, 0, segsize) );
    }

    // [引数]
    //          int a    : クエリの範囲の左端
    //          int b    : クエリの範囲の右端
    //          int k    : 今いるノードの場所
    //          int l    : 今いるノードの参照範囲の左端
    //          int r    : 今いるノードの参照範囲の右端
    // [動作]
    //          区間[a, b)のクエリを求める
    SEGNODE_TYPE SegQuery(int a, int b, int k, int l, int r) {
        // [a, b)の区間に対するクエリについて、ノードk(区間[l, r)担当)が答える
        if(r <= a || b <= l) {
            return (monoid);
        }
        if(a <= l && r <= b){
            // ノードkの担当クエリ区間[a ,b)に完全に含まれる
            return (value[k]);
        }
        else {
            // 左右の子に尋ねる
            SEGNODE_TYPE c1 = SegQuery(a, b, 2*k+1, l, (l+r)/2);    // 左の子（状況に合わせて型を変える）
            SEGNODE_TYPE c2 = SegQuery(a, b, 2*k+2, (l+r)/2, r);    // 右の子（状況に合わせて型を変える）
    
            return ( Requirement(c1, c2) ); // 左右の子から求めたいものを返す
        }        
    }

    // 求めたいもの
    // ※ここのreturn文は用途に合わせて書き換える必要がある
    SEGNODE_TYPE Requirement(SEGNODE_TYPE x, SEGNODE_TYPE y) {
        return ( x + y );
    }

    // [引数]
    //          int i   : 場所
    // [動作]
    //          左からi番目の値を変えす
    SEGNODE_TYPE GetReaf(int i) {
        return( value[i + segsize - 1] );
    }
};

int main() {
    int n, q, a, x, y, z;
    long long node;

    cin >> n >> q;
    Segtree fen = Segtree(n, 0, 0);

    for ( int i = 0; i < n; i++ ) {
        cin >> a;
        fen.UpDate(i, a);
    }

    for ( int i = 0; i < q ; i++ ) {
        cin >> x >> y >> z;

        if ( x == 0 ) {
            node = fen.GetReaf(y);
            node = node + z;

            fen.UpDate( y, node );
        } else {
            cout << fen.Query(y, z-1, n) << endl;
        }
    }

    return (0);
}