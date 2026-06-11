#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    ll K;
    cin >> S >> K;
    ll cnt=0;
    char bf=S[0];
    ll ac=0;
    for(int i=0;i<S.size();i++){
        if(i==S.size()-1){
            if(S[i-1]==S[i]){
                cnt++;
            }
            ac+=cnt/2;
            break;
        }
        if(S[i]!=bf){
            ac+=cnt/2;
            cnt=1;
            bf=S[i];
        }else{
            cnt++;
        }
    }
    if(S[0]==S[S.size()-1]){
        ll cnt_h=0;
        for(int i=0;i<S.size();i++){
            if(S[i]!=S[0]){
                break;
            }else{
                cnt_h++;
            }
        }
        if(cnt_h==S.size()){
            cout << S.size()*K/2 << endl;
            return 0;
        }
        ll cnt_t=0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]!=S[S.size()-1]){
                break;
            }else{
                cnt_t++;
            }
        }
        //cout << ac << " " << cnt_h << " " <<  cnt_t << endl;
        cout << K*ac - (cnt_h/2 + cnt_t/2 - (cnt_h+cnt_t)/2)*(K-1) << endl;
    }else{
        cout << K*(ac) << endl;
    }
    return 0;
}