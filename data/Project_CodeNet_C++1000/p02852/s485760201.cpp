//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};

//探索、更新にO(log n)
struct segment_tree{
    int init ; //　空いてる値はこれになる
    int n; //　n個のデータ
    vector<int> data; // データ置き場・n-1~2n-1に元データ

    //(個数、初期値)
    //初期化　nを2の累乗に直す  初期値は最も選ばれない値にする
    segment_tree(int a, int b) : init(b) {
        n = 1;
        while( n < a ) n *= 2;
        data.assign(n * 2 - 1,init);
    }

    //+とかにしてもいい、結合法則はいる
    //選ぶ方の決め方（ここでは小さい方）
    int which(int a, int b){
        if(a > b) return b;
        else return a;
    }

    // k番目をaに更新
    void update(int k, int a){
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
    int query( int a, int b, int k, int l, int r){

        // [a, b)と[l, r)が交差しなければ、MAX_INT
        if(r <= a || b <= l) return init;

        // [a, b)が[l, r)を完全に含んでいれば、この節点の値
        if(a <= l && r <= b) return data[k];

        // そうでなければ、2つの子の最小値
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return which( vl, vr );
    }

    // 外から呼ぶとき用
    // [a, b)の最小値を求める
    int query( int a, int b){
        return query( a, b, 0, 0, n);
    }

    int look(int a){
        return query(a,a+1);
    }
};


int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;

    segment_tree sg(n+1, inf);
    sg.update(0,0);

    REP(i,1,n+1){
        if(s[i]=='1') continue;
        int x = sg.query(max(0,i-m), i);
        if(x==inf) continue;
        else sg.update(i,x+1);
    }

    int x = sg.look(n);

    if(x==inf){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> move(x+1,-1);
    move[x]=n;
    x --;

    for(int i = n-1; i>=0; i--){
        if(sg.look(i)==x){
            move[x] = i;
            x --;
        }
        if(sg.look(i)==x+1 && i+m>=move[x+2] && x+2!=move.size()){
            move[x+1] =i;
        }
    }

    rep(i,move.size()-1){
        cout<<move[i+1]-move[i];
        if(i!=move.size()-2) cout<<" ";
        else cout<<endl; 
    }

    // cout<<"data: ";
    // rep(i,n+1) cout<<sg.look(i)<<" ";
    // cout<<endl;

    // cout<<"move: ";
    // for(auto y:move) cout<<y<<" ";
    // cout<<endl;
}/*
./problem.exe
*/