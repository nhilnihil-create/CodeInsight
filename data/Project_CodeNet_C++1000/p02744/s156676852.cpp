#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;

int n;

void dfs(string s, char mc){
    if(s.size() == n){
        cout << s << endl;
    }else{
        for(char c = 'a'; c <= mc; c++){
            char nc = c == mc ? (char)(mc + 1) : mc;
            dfs(s + c, nc);
        }
    }
}

int main() {
    cin >> n;
    dfs("", 'a');

    return 0;
}
