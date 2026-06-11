#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    int n, snuke[2], fnuke[2];
    string s;
    cin >> n >> snuke[0] >> fnuke[0] >> snuke[1] >> fnuke[1] >> s;
    s = '#' + s + '#';
    for(int i = snuke[0]; i <= max(snuke[1], fnuke[1]); i++){
        if(s[i] == '#' && i-1 > 0){
            if(s[i-1] == '#'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if(snuke[1] < fnuke[1]){
        cout << "Yes" << endl;
        return 0;
    }else{
        for(int i = fnuke[0]; i <= fnuke[1]; i++){
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
}
