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
    ll N,M;
    cin>>N>>M;
    string S;
    cin>>S;
    vector<int> ans;
    vector<int> pos_ok;
    REP(i,N+1){
        if(S[i]=='0') pos_ok.push_back(N-i);
    }

    sort(ALL(pos_ok));
    int x=0;
    while(x!=N){
        auto itr=upper_bound(pos_ok.begin(),pos_ok.end(),x+M);
        itr--;
        int next=*itr;
        if(x==next){
            cout<<-1<<endl;
            return 0;
            break;
        }else{
            ans.push_back(next-x);
        }
        x=next;
    }

    REP(i,ans.size()){
        cout<<ans[ans.size()-1-i];
        if(i==ans.size()-1){
            cout<<endl;
        }else{
            cout<<" ";
        }
    }

}