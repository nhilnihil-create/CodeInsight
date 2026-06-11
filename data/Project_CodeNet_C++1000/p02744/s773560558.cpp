#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;
string s;
vector<string> ans;

void dfs(string& s,int m){
    if(s.size()>n){
        ans.emplace_back(s);
        return;
    }
    for(int i = 0; i < m; i++) {
        s.push_back(char(i+'a'));
        dfs(s,m);
        s.pop_back();
    }
    s.push_back(char(m+'a'));
    dfs(s,m+1);
    s.pop_back();
}

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin >> n;
    n--;
    s="a";
    dfs(s,1);
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}