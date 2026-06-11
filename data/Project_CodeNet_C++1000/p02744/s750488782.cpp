#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;


int n; 

void dfs(string s, char mx) {
    if(s.size() == n){
        cout << s << endl;
        return;
    }
    for(char c = 'a'; c <= mx+1; c++){
        //c++ではcharは数字でもたれている
        string t = s;
        t += c;
        dfs(t, max(mx, c));
    }
}

int main(){
    cin >> n;
    dfs("", 'a'-1);
    return 0;
}