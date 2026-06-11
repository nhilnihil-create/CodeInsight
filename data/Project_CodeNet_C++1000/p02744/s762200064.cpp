#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //配列(vector)vの重複要素を削除

void dfs(string s, int end, int num){
    if(s.size()==end){
        cout << s << endl;
        return;
    }

    for(char i='a'; i<='a'+num; i++){
        if(i<'a'+num) dfs(s+i, end, num);
        else dfs(s+i, end, num+1);
    }
}

void solve(){
    int N;
    cin >> N;
    dfs("a", N, 1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}