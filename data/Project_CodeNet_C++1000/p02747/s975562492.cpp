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
 
    string str;
    cin >> str;

    if(str.size()%2 != 0){
        cout << "No" << endl;
        return 0;
    }

    for(int i = 0; i < str.size(); i += 2){
        if(str[i] != 'h' || str[i+1] != 'i'){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}