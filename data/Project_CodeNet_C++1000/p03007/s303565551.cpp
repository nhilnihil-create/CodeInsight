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

int main(){
    ll N;
    cin>>N;
    vector<ll> A(N),A_minus,A_plus;
    REP(i,N){
        cin>>A[i];
        if(A[i]>=0) A_plus.push_back(A[i]);
        else A_minus.push_back(A[i]);

    }
    sort(ALL(A));
    sort(ALL(A_minus));
    sort(ALL(A_plus));
    
    ll sum=0;
    vector<pair<ll,ll>> ans(N-1);
    if(A_minus.size()==0){
        ll x,y;
        x=A[0];
        y=A[1];
        ans[0]=make_pair(x,y);
        REP2(i,1,N-1){
            x-=y;
            y=A[i+1];
            if(i==N-2){
                sum=y-x;
                ans[i]=make_pair(y,x);
                break;
            }
            ans[i]=make_pair(x,y);   
        }
    }else if(A_plus.size()==0){
        ll x,y;
        sort(ALL(A),greater<ll>());
        x=A[0];
        y=A[1];
        ans[0]=make_pair(x,y);
        REP2(i,1,N-1){
            x-=y;
            y=A[i+1];
            ans[i]=make_pair(x,y);   
        }
        sum=x-y;
    }else{
        ll x,y;
        //マイナス1個とプラス多数
        x=A_minus[0];
        REP(i,A_plus.size()-1){
            y=A_plus[i];
            ans[i]=make_pair(x,y);
            x-=y;
        }
        ll y_last=x;
        //プラス1個とマイナス多数
        x=A_plus[A_plus.size()-1];
        REP2(i,1,A_minus.size()){
            y=A_minus[i];
            ans[A_plus.size()-2+i]=make_pair(x,y);
            x=x-y;
        }
        ans[N-2]=make_pair(x,y_last);
        sum=x-y_last;

    }
    cout<<sum<<endl;
    REP(i,N-1){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

}