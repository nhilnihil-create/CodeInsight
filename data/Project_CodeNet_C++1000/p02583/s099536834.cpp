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

bool check(ll a, ll b, ll c){
    vector<long long> lines = {a, b, c};
    sort(lines.begin(), lines.end());
    bool ans = false;
    if(lines[2] < lines[1] + lines[0]) ans = true;
    return ans;
}

int main(){
    int n;
    cin >> n;
    vll l(n);
    rep(i, n) cin >> l[i];

    long long ans = 0;
    {
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    auto a = l[i];
                    auto b = l[j];
                    auto c = l[k];
                    if(a == b || b == c || c == a) continue;
                    if(check(a, b, c)) ans++;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
