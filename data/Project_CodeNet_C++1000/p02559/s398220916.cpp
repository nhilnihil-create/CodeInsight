//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const in inf=1e9+7;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};

//探索、更新にO(log n)
struct segment_tree{
    in init ; //　空いてる値はこれになる
    in n; //　n個のデータ
    vector<in> data; // データ置き場・n-1~2n-1に元データ

    //(個数、初期値)
    //初期化　nを2の累乗に直す  初期値は最も選ばれない値にする
    segment_tree(in a, in b) : init(b) {
        n = 1;
        while( n < a ) n *= 2;
        data.assign(n * 2 - 1,init);
    }

    //+とかにしてもいい、結合法則はいる
    //選ぶ方の決め方（ここでは小さい方）
    in which(in a, in b){
        // if(a > b) return b;
        // else return a;
        return a+b;
    }

    // k番目をaに更新
    void update(in k, in a){
        k += n-1;
        data[k] = a;

        //下から上に更新
        while( k > 0 ){
            k = (k - 1) / 2;
            data[k] = which( data[k*2+1] , data[k*2+2] );
        }
    }

    // [a, b)の最小値を求める
    // 後ろのほうの引数は、計算の簡単のための引数。
    // kは節点の番号、l, rはその節点が[l, r)に対応づいていることを表す。
    // したがって、外からはquery(a, b, 0, 0, n)として呼ぶ。
    in query( in a, in b, in k, in l, in r){

        // [a, b)と[l, r)が交差しなければ、MAX_in
        if(r <= a || b <= l) return init;

        // [a, b)が[l, r)を完全に含んでいれば、この節点の値
        if(a <= l && r <= b) return data[k];

        // そうでなければ、2つの子の最小値
        in vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        in vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return which( vl, vr );
    }

    // 外から呼ぶとき用
    // [a, b)の最小値を求める
    in query( in a, in b){
        return query( a, b, 0, 0, n);
    }

    // a番目のデータを見る
    // query(a,a+1)で良くね？
    in look(in a){
        return data[a+n-1];
    }
};

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n,q;
    cin>>n>>q;
    vector<in> a(n);
        rep(i,n) cin>>a.at(i);
    
    segment_tree sg(n,0);
    rep(i,n) sg.update(i,a[i]);
    in x,y,z;
    rep(i,q){
        cin>>x>>y>>z;
        if(x){
            cout<<sg.query(y,z)<<endl;
        }
        else{
            sg.update(y,sg.look(y)+z);
        }
    }
}/*
./problem.exe
*/