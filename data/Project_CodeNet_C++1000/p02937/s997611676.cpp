//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1e+9+7 //10^9+7
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>=(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入



int main(){
    string s,t;
    cin >> s >> t;
    int N_t=t.size();
    int N_s=s.size();
    vector<int> alpha_s[26];
    vector<bool> bool_s(26,false);
    int char_cur;

    //s数え上げ
    REP(i,N_s){
        char_cur=s[i]-'a';
        alpha_s[char_cur].push_back(i);
        bool_s[char_cur]=true;
    }

    //t数え上げ
    REP(i,N_t){
        char_cur=t[i]-'a';
        if(bool_s[char_cur]==false){
            cout << -1 << endl;
            return 0;
        }
    }


    int num_cur=-1;
    int itr;
    ll ans=0;
    REP(i,N_t){
        char_cur=t[i]-'a';
        itr=upper_bound(alpha_s[char_cur].begin(),alpha_s[char_cur].end(),num_cur)-alpha_s[char_cur].begin();
        if(itr==alpha_s[char_cur].size()){

            ans+=(N_s-(num_cur-alpha_s[char_cur][0]));
            num_cur=alpha_s[char_cur][0];
        }else{
            ans+=(alpha_s[char_cur][itr]-num_cur);
            num_cur=alpha_s[char_cur][itr];

        }
    }
    cout << ans << endl;
}