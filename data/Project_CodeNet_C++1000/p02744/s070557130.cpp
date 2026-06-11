#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

int N;

void dfs(string &S, int N, int val){
    if(N == 0){
        cout << S << endl;
        return;
    }
    for(int i=0; i<=val; i++){
        S.push_back(i+'a');
        dfs(S, N-1, i==val ? i+1:val);
        S.pop_back();
    }
}

int main(){
    cin >> N;
    string S="";
    dfs(S, N, 0);
    return 0;
}