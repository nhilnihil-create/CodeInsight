#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    int turn=0;
    char now=s[0];
    rep(i,n){
        if(now!=s[i]){
            turn++;
            now=s[i];
        }
    }
    //反転回数が同じなら幸福な人は同じ
    //LLLRLL,RRLLLR,,,
    //1回の操作で反転回数は2減る
    if(turn<=2*k){
        cout<<n-1<<endl;
    }
    else{
        turn-=2*k;
        cout<<n-1-turn<<endl;
    }
    return 0;
}