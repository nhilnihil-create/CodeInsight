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
 
ll ans=0;
void dfs(vector<int> &A,vector<int> a,vector<int> b,vector<int> c,vector<int> d){
    if(A.size()==N){
        ll tmp=0;
        for(int i=0;i<Q;i++){
            if(A[b[i]]-A[a[i]]==c[i]) tmp+=d[i];
        }
        ans=max(ans,tmp);
        return;
    }
 
    if(A.size()==0){
        for(int v=0;v<M;++v){
            A.push_back(v);
            dfs(A,a,b,c,d);
            A.pop_back();
        }
    }else{
        for(int v=A[A.size()-1];v<M;++v){
            A.push_back(v);
            dfs(A,a,b,c,d);
            A.pop_back();
        }
    }
    
 
}
int main(){
    cin>>N>>M>>Q;
    vector<int> a(Q),b(Q),c(Q),d(Q);
    REP(i,Q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;
        b[i]--;
    }
    
    //全探索
    vector<int> A;
    dfs(A,a,b,c,d);
    cout<<ans<<endl;
 
    
}