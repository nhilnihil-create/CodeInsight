//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int N,M,Q;
vector<ll> a,b,c,d;

ll score(const vector<int> &A){
    ll res=0;
    for(int i=0;i<Q;i++){
        if(A[b[i]]-A[a[i]]==c[i]) res+=d[i];
    }
    return res;
}

ll dfs(vector<int> &A){
    if(A.size()==N){
        return score(A);
    }

    ll res=0;

    int start=(A.empty() ? 0 : A.back() );
    for(int v=start;v<M;++v){
        A.push_back(v);
        res=max(res,dfs(A));
        A.pop_back();
    }
    return res;
}

int main(){
    cin>>N>>M>>Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    
    REP(i,Q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;
        b[i]--;
    }
    
    //全探索
    vector<int> A;
    cout<<dfs(A)<<endl;

    
}