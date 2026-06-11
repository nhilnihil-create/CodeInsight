#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

int K;
set<ll> ss;

void dfs(string &S, int cur=0){
    if((int)S.size()){
        if(stoll(S) > (ll)1e10) return;
        else{
            ss.insert(stoll(S));
        }
    }
    for(int i=0; i<=9; i++){
        if(cur == 0 && i == 0) continue;
        if(cur != 0 && abs(S[cur-1]-'0'-i) > 1) continue;
        S.push_back(i+'0');
        dfs(S, cur+1);
        S.pop_back();
    }
}

int main(){
    cin >> K;
    string S="";
    dfs(S);
    ll res;
    for(auto &x: ss){
        K--;
        if(K == 0) res=x;
    }
    cout << res << endl;
    return 0;
}