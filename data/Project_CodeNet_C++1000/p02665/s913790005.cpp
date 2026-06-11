#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>
#include<list>

/*
　　　　　　　　　　　　　　　　　　　　　__,.二ﾆ==-　　ﾆ．、_.　　　　　　　　　　　　　　　　　　　　　
　　　　　　　　　　　　　　　　.,.．‐　⌒　　　　　　　　　　　　｀`'ァ-ﾆ、.　　　　　　　　　　　　　　　
　　　　　　　　　　　　　　ィ'´.　　　　　　　　　　　　　　　　　　　　　　´丶.、　　　　　　　　　　　　
　　　　　　　　　　　.,ィ'´　　　　　　　　　　　　　　　　　　　　　　　　　　　　`.ｘ、..　　　　　　　　　
　..　　　　　　　　／.　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　､＼.　　　　　　　　
　　　　　　　　.ﾝ′.　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　￢`""冖ｰミト．
　　　　　　　,ｒ′.　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　.ﾍ、　　　　`
　　　　　　ﾂ　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　`、....　　　
　　　　　./´　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　ﾍ　　　　
　.....　　/.　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　.〉.　　　
　　　´/..　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　.ｌ　　　
　　　ｨ　　　　　　　　　　　　　　　　　　　　　　　　　．　　　　　　　　　　　　　　　　　　　　　ｆ..　　
　..　.ｆ　,d.　　　　　　　　　　　　　　　　　l　　　′　」　　,.　　　　　　　　　　　　　ﾄ　　　　　！　　
　.　〕../.ｆ..　　　　　　　　　　　　　　　　　′　．.　　|　　.｝　　　　　　　　　　　　　|　　　　　　|.　　
　　.!./..f..　　　　　　　　　　　　　　　　　/　　!－　ナ丶п冖т　　　　ﾉｰ-　．　〕　　　　　　|.　　
　　|ﾒ　|　　　　　　　　　　　　　　　｜　j　　　　　　,　　┌．　|〈.　　　л`.　　　/|..　　　　　┤,..　
　...「...｜.　　　　　　|　　´　　　　　　l.　|　　j.Ｌ......ｭ.Ｌ＿└ヽ_｜Y.　　ﾒムｗ　ょ　|　　j.:　　　|　￣
　.　　｜.　　　　　　　　　　　　　　　т〕＜.ィ冖T冖..　г‐　`､　`,　/┴￢..г￣|..　.′　　｜　　
　...　　|　　　　　　　　．..　　　　　　　),|..　｀　　ﾘ　「_ﾉ.||　　　　`　V　　|!｛,｢ll　´.」.　　　　　卜　　
　.　　｜.」　　　　　　′　　　　　　　　ヽ　　　　└++〃..　　　　　　　　ﾙｗｆ　　ｶz′.　　　｜.　　
　　　　|..〕　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｢　　　　　．|　　　
　　　　.ｌ.|.　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　′.　　　　　|　　　
　.　　　.〕..　　　　　　　　　　　　　　　`!　　　　　　　　_...．.ｰ：''　　　　　　　　　｣　´　　　　λ.　　
　　　　_｢.　　　　,　　　　　　　　　　　　┐_,、｀~‐''"´　　　　　　　　　　　　　　　　ィ　　　.､　ﾍ、　
　　　　ｆ　　　　　　:_＿..,二ュ．-i―'''^~´　　　　　　　　　　　　　　　　　　　　　　　､＼イ　ヘ．`ｘ
　.　　/　　　　　　｛　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　j　　　　.~^
　　､/　　　　　　　'ｔ..　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　丿..　　　　　
　.../.　　　　　　　,x┐..　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　∠∫　　　　　
　:^.　　　　　　　/　　￣冖ー=zzｭ┌ｰ―--　　　∟,二...＿.　　　　　　　_,､．-ｰ.'l+~.　.l｀．　　　　
　.　　　　　　　У.　　　　　　　　　⌒冖‐-=．_..　l｢.｢　　　　　　´￣｣了　　.,､-''＾　　　〉　ヽ_　　　
　　　　　　　_/.　　　　　　　　　　　　　　　　　　￣~'.ー-=．、＿,..usｧ.ｰ''"　　　　　　｛　　　＼´　
　　　　　　_ヰl'￢―-　､_　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　（　　　　.＼
*/

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll mypow(ll x,ll n,ll mod = MOD){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret = (ret*x)%mod;
        }
        x = (x*x)%mod;
        n >>= 1;
    }
    return ret;
}

ll mygcd(ll a,ll b){
    if(b == 0)return a;
    return mygcd(b,a%b);
}

ll twoPow(ll shiftNum){
    return (1LL << (shiftNum - 1));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    ll n;
    cin >> n;

    vector<ll> a(n+1);
    for(auto &x: a){
        cin >> x;
    }

    vector<ll> need(n+1);
    need[n] = a[n];
    vector<ll> mx(n+1);
    mx[n] = a[n];

    for(int i = n-1; i >= 0; i--){
        need[i] = (need[i+1] + 1)/2 + a[i];
        mx[i] = mx[i+1] + a[i];
    }


    ll nn = 1;
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        nn -= a[i];
        ans += a[i];
        if(i == n){
            break;
        }
        if((need[i+1]+1)/2 <= nn && nn <= mx[i+1]){
            ans += nn;
            nn = min(mx[i+1],nn*2);
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(nn == 0){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}