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

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    string N;
    cin >> N;
    int num;
    ll ans=0;
    bool flag=false;
    REP(i,N.size()){
        num=N[N.size()-1-i]-'0';
        if(flag){
            num++;
            flag=false;
        }
        if(num>5){
            flag=true;
            ans+=(10-num);
        }else if(num==5){
            if(N[N.size()-1-i-1]-'0'<=4){
                flag=false;
            }else{
                flag=true;
            }
            ans+=5;
        }else{
            ans+=num;
        } 
    }
    if(flag) ans++;
    cout << ans <<endl;
}