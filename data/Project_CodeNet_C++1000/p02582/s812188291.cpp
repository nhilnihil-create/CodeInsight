#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;


int main(){
    string s;
    cin >> s;

    int ans = 0;

    int tmp = 0;
    bool flag = false;
    for(auto c : s){
        if(c == 'R' && !flag){
            flag = true;
            tmp++;
        }
        else if(c == 'S'){
            ans = max(ans, tmp);
            flag = false;
            tmp = 0;
        }
        else if(c == 'R' && flag){
            tmp++;
        }
    }

    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}
