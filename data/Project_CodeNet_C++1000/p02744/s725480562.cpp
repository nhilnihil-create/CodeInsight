#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll N;
vector<string> ans;

void dfs(string s){
    ll n = s.size();
    if(n == N){
        ans.push_back(s);
        return;
    }
    char mx = 'a';
    for(auto ss : s) mx = max(mx, ss);
    for(char c = 'a'; c <= mx + 1; c++){
        dfs(s+c);
    }
}

int main(){
    cin >> N;
    dfs("a");
    sort(ans.begin(),ans.end());
    for(auto q : ans) cout << q << endl;
    return 0;
}
