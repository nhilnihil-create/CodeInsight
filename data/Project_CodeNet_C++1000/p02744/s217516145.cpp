#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int n;
void dfs(string s, char c){
    if(s.size() == n){
        cout << s << "\n";
    }else{
        for (char cc = 'a'; cc <= c; ++cc) {
            if(cc == c){
                dfs(s+cc, c+1);
            }else{
                dfs(s+cc, c);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;

    dfs("", 'a');

    return 0;
}
