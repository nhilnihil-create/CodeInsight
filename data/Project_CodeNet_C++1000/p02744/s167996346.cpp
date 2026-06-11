#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n;
void dfs(string s,char mx) {
    if(s.size()==n) {
        cout << s << endl;
        return;
    }
    for(char i = 'a';i<=mx;i++) {
        string t = s;
        t += i;
        dfs(t,max(mx,(char)(i+1)));
    }
}
int main() {
    cin >> n;
    dfs("",'a');
}